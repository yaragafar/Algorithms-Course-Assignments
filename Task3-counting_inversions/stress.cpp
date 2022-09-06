#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "naive_inversion.h"
#include "dandq_inversion.h"

#define ARRAY_SIZE 1e6
using namespace std;


vector<int> generate_random_vector()
{
    /**
 * generate a 1d-vector with size = variable size
 *
 * @return
 * a 1d vector with size 128*128 contains random numbers
 *
 */
    int n = 200;
    vector<int> v(n);
    srand(time(0));

    for (int i = 0; i < n; ++i)
    {
        v[i] = rand();
    }

    return v;    
}


int main(int argc, char** argv)
{
    /**
 * driving stress test for both algorithms
 *
 * generate a 1d-vector with fixed size
 * compare their output and runnig time
*/
    while (true)
    {
        vector<int> a = generate_random_vector();
        int naive_result, dandq_result;

        auto naive_start = std::chrono::high_resolution_clock::now();
        naive_result = naive_counting_inversions(a);
        auto naive_finish = std::chrono::high_resolution_clock::now();

        auto dandq_start = std::chrono::high_resolution_clock::now();
        dandq_result = dandq_counting_inversions(a);
        auto dandq_finish = std::chrono::high_resolution_clock::now();

        auto naive_time = (naive_finish - naive_start).count();
        auto dandq_time = (dandq_finish - dandq_start).count();

        if (dandq_result == naive_result)
        {
            cout << "equivalent ";
            cout << "naive_time ==> " << naive_time;
            cout << "dandq_time ==> " << dandq_time;
            cout << "performance enhancment ==> " << float(naive_time) / dandq_time << endl;
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