#pragma once
#include <iostream>
#include <vector>
using namespace std;

int naive_counting_inversions(vector<int> a) {

	/**
	 *
	 * @param
	 *  a --> 1d array
	 *
	 * @return
	 * the number of inversions in the array
	*/

	int inversions_count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[i] > a[j])
			{

				swap(a[i], a[j]);
				inversions_count++;
			}

		}

	}

	return inversions_count;


}

