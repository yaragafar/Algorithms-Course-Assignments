//#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

#define ARRAY_SIZE 1e6
using namespace std;

/**
 * generate 1d vector with size = ARRAY_SIZE
 *
 * @param
 *
 * isRandom --> boolean variable to return random or sorted array
 * if isRandom == true, then the array should look like this [0, 1, 2, 3]
 *
 * @return
 *  a 1d vector with size = ARRAY_SIZE, you have the choice to pass vector by reference or to return a vector
 * make sure to change the code in main to match your change
 *
 */





vector<int> generate_random_vector()

{
	int n = 15;
	vector<int> v(n);
	srand(time(0));

	for (int i = 0; i < n; ++i)
	{
		v[i] = rand();
	}

	return v;
}


void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

// function to partition at a certain index
//it gives the pivot its sorted position
int Partition(vector<int>& vec, int l, int h) {
	int p_index = l;
	int pivot = vec[h];

	for (int i = l; i < h; i++)
	{
		if (vec[i] <= pivot)
		{
			swap(vec[i], vec[p_index]);
			p_index++;
		}
	}

	swap(vec[h], vec[p_index]);
	return p_index;

}

void insertion_sort(vector<int>& v, int left, int right)
{
	int i, j, tmp;

	for (i = 1; i < v.size(); i++)
	{
		j = i;
		tmp = v[i];
		while (j > 0 && tmp < v[j - 1])
		{
			v[j] = v[j - 1];
			j--;
		}
		v[j] = tmp;
	}
}

// Function to perform heapsort on the given range of elements
void heap_sort(vector<int>& v)
{
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());
}

void intro_sort(vector<int>& v, int l, int h, int depth)
{
	int n = v.size();
	if (n <= 16)
	{

		insertion_sort(v, l, h);

	}

	else if (depth == 0)
	{
		heap_sort(v);
	}

	else
	{
		int part_index = Partition(v, l, h);
		intro_sort(v, l, part_index - 1, depth - 1);
		intro_sort(v, part_index + 1, h, depth - 1);

	}


}


void Sort(vector<int>& v)
{

	int l = v[0];
	int h = v[v.size() - 1];
	int depth_limit = 2 * log(v.size());
	intro_sort(v, l, h, depth_limit);

}


// function to partition at a certain index
//it gives the pivot its sorted position
int partition(vector<int>& vec, int l, int h)
{
	int p_index = l;
	int pivot = vec[h];

	for (int i = l; i < h; i++)
	{
		if (vec[i] <= pivot)
		{
			swap(vec[i], vec[p_index]);
			p_index++;
		}
	}

	swap(vec[h], vec[p_index]);
	return p_index;

}



//function to recursively sort left and right of partition index
void quicksort(vector<int>& v, int l, int h)
{
	if (l < h)
	{
		int part_index = partition(v, l, h);
		quicksort(v, l, part_index - 1);
		quicksort(v, part_index + 1, h);

	}

}


int main(int argc, char** argv)
{
	while (true)
	{

		vector<int> a = generate_random_vector();
		vector<int> b = a; //copy array A into array B
		vector<int> sorted_array = a;
		sort(sorted_array.begin(), sorted_array.end());

		auto quick_start = std::chrono::high_resolution_clock::now();
		quicksort(a, 0, a.size() - 1);
		auto quick_finish = std::chrono::high_resolution_clock::now();

		auto intro_start = std::chrono::high_resolution_clock::now();

		Sort(b);
		auto intro_finish = std::chrono::high_resolution_clock::now();

		auto quick_time = (quick_finish - quick_start).count();
		auto intro_time = (intro_finish - intro_start).count();

		if (a == sorted_array && b == sorted_array)
		{
			cout << "equivalent result ";
			cout << "quick_time ==> " << quick_time;
			cout << "intro_time ==> " << intro_time;
			cout << "performance enhancment ==>" << quick_time / intro_time << endl;
			break;
		}
		else
		{
			cout << "error, check your inputs and algortihms " << endl;
			// you may want to store your variables in a file to re-run the test on the same inputs;
			break;
		}
	}
	return 0;
}