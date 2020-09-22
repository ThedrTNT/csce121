#include <iostream>
// not other include files are allowed

using std::cin, std::cout, std::endl;

// PUT YOUR FUNCTION HERE
template <typename T>
T* rotate(const T A[], int n, int k) {
  T* retArr = new T[n];
  for (int i = 0; i < n; ++i) {
    retArr[i] = A[i];
  }
  
  if (k == 0) {
    return retArr;
  }
  if (k > 0) {
    T* tempArr = new T[k];
    for (int i = n - k; i < n; ++i) {
      tempArr[i - (n - k)] = retArr[i];
    }
    
    for (int i = k; i < n; ++i) {
      retArr[i] = retArr[i - k];
    }
    for (int i = 0; i < k; ++i) {
      retArr[i] = tempArr[i];
    }
    delete[] tempArr;
  }
  if (k < 0) {
    int x = 0 - k;
    T* tempArr = new T[x];
    for (int i = 0; i < x; ++i) {
      tempArr[i] = retArr[i];
    }
    for (int i = 0; i < n - x; ++i) {
      retArr[i] = retArr[i + x];
    }
    for (int i = n - x; i < n; ++i) {
      retArr[i] = tempArr[i - (n - x)];
    }
    delete[] tempArr;
  }
  
  return retArr;
}

int main() {
  // write your own tests here
  {
    int A[] = {1, 2, 3, 4, 5};
    int expected[] = {4, 5, 1, 2, 3};
    int* actual = rotate(A, 5, 2);
    for (size_t i = 0; i < 5; ++i) {
      if (actual[i] != expected[i]) {
        cout << "[FAIL] expected actual["<<i<<"] to be " << expected[i] << endl;
      }
    }
  }
  
}