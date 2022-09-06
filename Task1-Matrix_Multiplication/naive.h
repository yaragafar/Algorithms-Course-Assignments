#pragma once
#ifndef NAIVE_H
#define NAIVE_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>  naive(vector<vector<int>> a, vector<vector<int>> b) 
{

	//we create matrix c to store the product of a*b
	vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 0));


	if (a[0].size() != b.size()) {
		cout << "Multiplication isn't valid .. please choose matrices with appropirate dimensions";
	}

	else {
		//a(m,n)
		//b(n,l)
		//c(m,l)
		int m, l = 0;
		//for each row in a
		for (m = 0; m<int(a.size()); m++)
		{ //and each column of b
			for (l = 0; l<int(a[m].size()); l++)
			{
				c[m][l] = 0;

				for (int k = 0; k < int(a[m].size()); k++) {

					c[m][l] += a[m][k] * b[k][l];

				}
			}
		}
	}

	return c;
}

#endif
