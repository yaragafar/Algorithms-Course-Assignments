#pragma once
#include <iostream>
#include <vector>
using namespace std;


int merge(vector<int>& a, int l, int h, int mid)
{//merges two sorted vectors into a sorted vector
	int inversion_count = 0;

	//sizes of the two sub vectors
	int m = mid - l + 1;
	int n = h - mid;

	//initialization of size and 0 values matter -->> very important
	vector<int> a_left(m, 0);
	vector<int> a_right(n, 0);
	//creating the two sub-vectors
	for (int i = 0; i < m; i++)
	{
		a_left[i] = a[l + i];
	}
	for (int j = 0; j < n; j++)
	{
		a_right[j] = a[j + mid + 1];
	}

	int i = 0, j = 0, k = l;

	//merging sub-vectors 
	while (i < m && j < n)
	{
		if (a_left[i] < a_right[j])
		{
			a[k] = a_left[i];
			i++;
			k++;
		}
		else {
			a[k] = a_right[j];
			j++;
			k++;

			inversion_count = inversion_count + m - i;

		}
	}

	while (i < m) {       //extra element in left array
		a[k] = a_left[i];
		i++; k++;
	}
	while (j < n) {     //extra element in right array
		a[k] = a_right[j];
		j++; k++;
	}

	return inversion_count;

}

int merge_sort(vector<int>& a, int l, int h)
{// recursively splits the vector into two halves until it's a single element

	int inversion_count = 0; 
	if (l < h)
	{
		int mid = l + (h - l) / 2;

		inversion_count += merge_sort(a, l, mid);
		inversion_count += merge_sort(a, mid + 1, h);
		inversion_count += merge(a, l, h, mid);


	}
	return inversion_count;
}


int dandq_counting_inversions(vector<int> a) {
	int inversion_count = merge_sort(a, 0, a.size() - 1);

	return inversion_count;
}


 

