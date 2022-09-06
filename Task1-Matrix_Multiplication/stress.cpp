
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include "naive.h"
#include "strassen.h"
using namespace std;

vector<vector<int>> generate_random_vector()

{
	int n = 128;
	vector<vector<int>> v(n, vector<int>(n, 0));

	srand(time(0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = rand();
		}
	}

	return v;

}


int main(int argc, char** argv)
{

	while (true)
	{
		vector<vector<int>> a = generate_random_vector();
		vector<vector<int>> b = generate_random_vector();
		vector<vector<int>> naive_result;
		vector<vector<int>> strassen_result;

		auto naive_start = std::chrono::high_resolution_clock::now();
		// fill this line
		naive_result = naive(a, b);
		auto naive_finish = std::chrono::high_resolution_clock::now();

		auto strassen_start = std::chrono::high_resolution_clock::now();
		// fill this line
		strassen_result = strassen(128, a, b);
		auto strassen_finish = std::chrono::high_resolution_clock::now();

		auto naive_time = (naive_finish - naive_start).count();
		auto strassen_time = (strassen_finish - strassen_start).count();

		if (strassen_result == naive_result)
		{
			cout << "equivalent result " << endl;
			cout << "naive_time ==> " << naive_time << endl;
			cout << "strassen_time ==> " << strassen_time << endl;
			cout << "performance enhancment ==>" << naive_time / strassen_time << endl;
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