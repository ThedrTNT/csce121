// matrix_vertcat.cpp
#include <iostream>
#include <stdexcept>
#include "./matrix.h"

using std::cout, std::endl;
using std::invalid_argument;
using std::size_t;

// vertically concatenate B to A (A on top of B)
// throws an invalid_argument exception on mismatched dimensions
// side effects:
//   A is reallocated to be bigger
Matrix& vertcat(Matrix& A, Matrix const& B) {
  // TODO(student) : vertcat
	if(A.cols != B.cols) {
		throw invalid_argument("dimension mismatch");
	}
	size_t newRows = A.rows + B.rows;
	int** temp = new int*[A.rows];
	size_t tempRows = A.rows;
	size_t tempCols = A.cols;
	for (size_t i = 0; i < A.rows; ++i) {
		temp[i] = new int[A.cols];
	}

	for (size_t i = 0; i < A.rows; ++i) {
		for (size_t j = 0; j < A.cols; ++j) {
			temp[i][j] = A[i][j];
		}
	}

	A.data = new int*[newRows];
	A.rows = newRows;
	A.cols = tempCols;
	for (size_t i = 0; i < newRows; ++i) {
		A[i] = new int[A.cols];
	}

	for (size_t i = 0; i < tempRows; ++i) {
		for (size_t j = 0; j < tempCols; ++j) {
			A[i][j] = temp[i][j];
		}
	}

	for (size_t i = tempRows; i < newRows; ++i) {
		for (size_t j = 0; j < tempCols; ++j) {
			A[i][j] = B[i - tempRows][j];
		}
	}

	for (size_t i = 0; i < tempRows; ++i) {
		delete[] temp[i];
	}
	delete[] temp;

  return A;
}

Matrix::~Matrix() {
  // TODO(student): destructor
	for (size_t i = 0; i < rows; ++i) {
		delete[] data[i];
	}
	delete[] data;
	rows = 0;
	cols = 0;
	data = nullptr;
}