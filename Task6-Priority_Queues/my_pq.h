#pragma once
#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
using namespace std;

class My_PQ {

public:
    My_PQ() {}

   // My_PQ(vector<int> arr) {}

	int H[50];
	int the_size = -1;

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	int leftChild(int i)
	{

		return ((2 * i) + 1);
	}
	int rightChild(int i)
	{

		return ((2 * i) + 2);
	}

	void shiftUp(int i)
	{
		while (i > 0 && H[parent(i)] < H[i]) {

			// Swap parent and current node
			swap(H[parent(i)], H[i]);

			// Update i to parent of i
			i = parent(i);
		}
	}

	void shiftDown(int i)
	{
		int maxIndex = i;

		// Left Child
		int l = leftChild(i);

		if (l <= the_size && H[l] > H[maxIndex]) {
			maxIndex = l;
		}

		// Right Child
		int r = rightChild(i);

		if (r <= the_size && H[r] > H[maxIndex]) {
			maxIndex = r;
		}

		// If i not same as maxIndex
		if (i != maxIndex) {
			swap(H[i], H[maxIndex]);
			shiftDown(maxIndex);
		}
	}

	int extract_max()
	{
		int result = H[0];

		H[0] = H[the_size];
		the_size = the_size - 1;
		shiftDown(0);
		return result;
	}

	void change_priority(int index, int new_priority)
	{
		int oldp = H[index];
		H[index] = new_priority;

		if (new_priority > oldp) {
			shiftUp(index);
		}
		else {
			shiftDown(index);
		}
	}
    int peek() {
		return H[0];

	}

	void insert(int value)
	{
		the_size = the_size + 1;
		H[the_size] = value;
		shiftUp(the_size);
	}
	void remove(int index)
	{
		H[index] = peek() + 1;

		// Shift the node to the root
		// of the heap
		shiftUp(index);

		// Extract the node
		extract_max();
	}

	int pq_size()
	{
		return the_size+1;
	}

};


#endif