#include <vector>
#include <iostream>
using namespace std;


int knapsack_wor(int W, int n, vector<int> weights, vector<int> vals)
{
	vector<vector<int>> max_val(n + 1, vector<int>(W + 1));

	for (int j = 0; j <= n; j++)
	{
		for (int i = 0; i <= W; i++)
		{
			if (j == 0 || i == 0)
				max_val[j][i] = 0;
			else if (weights[j - 1] <= i)
				max_val[j][i] = max(vals[j - 1] +
					max_val[j - 1][i - weights[j - 1]],
					max_val[j - 1][i]);
			else
				max_val[j][i] = max_val[j - 1][i];
		}
	}
	return max_val[n][W];
}

int main()
{
	int n, W;
	cout << "Enter number of items and maximum weight" << endl;
	cin >> n >> W;

	vector<int> weights(n, 0);
	vector<int> vals(n, 0);

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

	int maximum_knapsack_value = knapsack_wor(W, n, weights, vals);
	cout << "Maximum Knapsack Value is " << maximum_knapsack_value;

	return 0;
}
