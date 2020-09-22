#include <iostream>

using namespace std;

double pathLength(double** distance, int n, int* path, int m) {
	double sumDist = 0;

	for (int i = 1; i < m; ++i) {
		if (path[i] < n && path[i - 1] < n) {
			sumDist += distance[path[i - 1]][path[i]];
		}
	}

	return sumDist;
}

int main() {
	int n = 5;
	double** distance = new double*[n];

	for (int i = 0; i < n; ++i) {
		distance[i] = new double[n];
	}

	distance[0][0] = 0;
	distance[0][1] = 30.0;
	distance[0][2] = 10.0;
	distance[0][3] = 70.0;
	distance[0][4] = 10.0;
	distance[1][0] = 30.0;
	distance[1][1] = 0;
	distance[1][2] = 45;
	distance[1][3] = 100.;
	distance[1][4] = 50;
	distance[2][0] = 10;
	distance[2][1] = 45.0;
	distance[2][2] = 0;
	distance[2][3] = 85.0;
	distance[2][4] = 20;
	distance[3][0] = 70.0;
	distance[3][1] = 100.0;
	distance[3][2] = 85.0;
	distance[3][3] = 0;
	distance[3][4] = 100;
	distance[4][0] = 10.0;
	distance[4][1] = 50.0;
	distance[4][2] = 20.0;
	distance[4][3] = 100.0;
	distance[4][4] = 0;

	int m = 6;
	int path[] = {0, 1, 0, 3, 2, 0};

	cout << pathLength(distance, n, path, m) << endl;
}