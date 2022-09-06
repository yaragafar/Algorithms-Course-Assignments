#pragma once
#ifndef STRASSEN_H
#define STRASSEN_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// adding two matrices
vector<vector<int>> sum(int n, vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C(n, vector<int>(n, 0));
	int i, j;

	for (i = 0; i <int(A.size()); i++) {
		for (j = 0; j < int(B.size()); j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}
// substracting two matrices
vector<vector<int>> sub(int n, vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C(n, vector<int>(n, 0));
	int i, j;

	for (i = 0; i < int(A.size()); i++) {
		for (j = 0; j <int(B.size()); j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}



vector<vector<int>> strassen(int n, vector<vector<int>> A, vector<vector<int>> B) {

	//creating the product matrix
	vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));


	if (n <= 2) {
		//for each row in a
		for (int m = 0; m < n; m++)
		{ //and each column of b
			for (int l = 0; l < n; l++)
			{
				C[m][l] = 0;

				for (int k = 0; k < n; k++) {

					C[m][l] += A[m][k] * B[k][l];

				}
				//	cout << C[m][l] << "\t";

			}

			//	cout << endl;

		}

		return C;
	}

	else {

		int new_n = n / 2;

		//creating the sub matrices of A with size (n/2,n/2)
		vector<vector<int>> a(new_n, vector<int>(new_n, 0));
		vector<vector<int>> b(new_n, vector<int>(new_n, 0));
		vector<vector<int>> c(new_n, vector<int>(new_n, 0));
		vector<vector<int>> d(new_n, vector<int>(new_n, 0));

		//creating the sub matrices of B with size (n/2,n/2)
		vector<vector<int>> e(new_n, vector<int>(new_n, 0));
		vector<vector<int>> f(new_n, vector<int>(new_n, 0));
		vector<vector<int>> g(new_n, vector<int>(new_n, 0));
		vector<vector<int>> h(new_n, vector<int>(new_n, 0));

		//creating the sub matrices of C with size (n/2,n/2)
		vector<vector<int>> c11(new_n, vector<int>(new_n, 0));
		vector<vector<int>> c12(new_n, vector<int>(new_n, 0));
		vector<vector<int>> c21(new_n, vector<int>(new_n, 0));
		vector<vector<int>> c22(new_n, vector<int>(new_n, 0));

		//creating the seven p matrices
		vector<vector<int>> p1(new_n, vector<int>(new_n, 0));
		vector<vector<int>> p2(new_n, vector<int>(new_n, 0));
		vector<vector<int>> p3(new_n, vector<int>(new_n, 0));
		vector<vector<int>> p4(new_n, vector<int>(new_n, 0));
		vector<vector<int>> p5(new_n, vector<int>(new_n, 0));
		vector<vector<int>> p6(new_n, vector<int>(new_n, 0));
		vector<vector<int>> p7(new_n, vector<int>(new_n, 0));

		//dividing the matrices in 4 sub-matrices:
		for (int i = 0; i < new_n; i++) {
			for (int j = 0; j < new_n; j++) {
				a[i][j] = A[i][j];
				b[i][j] = A[i][j + new_n];
				c[i][j] = A[i + new_n][j];
				d[i][j] = A[i + new_n][j + new_n];

				e[i][j] = B[i][j];
				f[i][j] = B[i][j + new_n];
				g[i][j] = B[i + new_n][j];
				h[i][j] = B[i + new_n][j + new_n];
			}
		}

		// Calculating p1 to p7:

		p1 = strassen(new_n, a, sub(new_n, f, h));

		p2 = strassen(new_n, sum(new_n, a, b), h);

		p3 = strassen(new_n, sum(new_n, c, d), e);

		p4 = strassen(new_n, d, sub(new_n, g, e));

		p5 = strassen(new_n, sum(new_n, a, d), sum(new_n, e, h));

		p6 = strassen(new_n, sub(new_n, b, d), sum(new_n, g, h));

		p7 = strassen(new_n, sub(new_n, a, c), sum(new_n, e, f));


		//putting results in c

		c11 = sum(new_n, sub(new_n, sum(new_n, p5, p4), p2), p6);

		c12 = sum(new_n, p1, p2);

		c21 = sum(new_n, p3, p4);

		c22 = sub(new_n, sub(new_n, sum(new_n, p5, p1), p3), p7);

		// Grouping the results obtained in a single matrix:
		for (int i = 0; i < new_n; i++) {
			for (int j = 0; j < new_n; j++) {
				C[i][j] = c11[i][j];
				C[i][j + new_n] = c12[i][j];
				C[i + new_n][j] = c21[i][j];
				C[i + new_n][j + new_n] = c22[i][j];
			}
		}

		return C;
	}
}

#endif