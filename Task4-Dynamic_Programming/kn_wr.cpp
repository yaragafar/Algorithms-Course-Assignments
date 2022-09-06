#include<iostream>
#include <vector>
using namespace std;


int knapsack_wr(int W,int n,vector<int> weights, vector<int> vals)
{
	vector<int> max_val(W+1);
	max_val[0] = 0;
	for (int i = 1; i <= W; i++)
	{
		max_val[i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (weights[j] <= i)
			{
				int value = max_val[i - weights[j]] + vals[j];
				if (value > max_val[i])
				{
					max_val[i] = value;
				}
		}
		}

	}
	return max_val[W];
}

int main()
{
	int n, W;



	cout << "Enter number of items and maximum weight" << endl;
	cin >> n >> W;

	vector<int> weights(n);
	vector<int> vals(n);

	cout << "Enter weigt of each item" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	cout << "Enter value of each item" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> vals[i];
	}

	int maximum_knapsack_value = knapsack_wr(W, n, weights, vals);
	cout << "Maximum Knapsack Value is " << maximum_knapsack_value;
}
