#include <vector>
#include "my_pq.h"
#include <iostream>
using namespace std;

int main()
{
    int size;
    int num_ops;

    My_PQ pq = My_PQ();

   // cout << "Enter size of your pq and number of operations to perform: ";
    cin >> size;
    cin >> num_ops;

    //cout << "Enter the elements to be inserted in the pq: ";
    vector<int> elements(size, 0);
    for (int i = 0; i < size; i++)
    {
        cin >> elements[i];
    }

    for (int i = 0; i < size; i++)
    {
        pq.insert(elements[i]);
    }


    for (int i = 0; i < num_ops; i++)
    {
        int op;
        //cout << "Choose an operation to be performed: " << endl;
        //cout << "1.insert an element in the pq" << endl;
        //cout << "2.change prioriry" << endl;
        //cout << "3.remove element" << endl;
        //cout << "4.extract max element" << endl;
        //cout << "5.peek max element and print it" << endl;
        //cout << "6.apply extract_max on every element in the heap and print the result" << endl;
        //cout << "7.print size of the heap" << endl;


        cin >> op;

        switch (op)
        {
        case 1:
            int p;
            cin >> p;
            pq.insert(p);
            break;

        case 2:
            int i;
            cin >> i;
            cin >> p;
            pq.change_priority(i, p);
            break;

        case 3:
            cin >> i;
            pq.remove(i);
            break;

        case 4:
            int max;
            max=pq.extract_max();
            break;

        case 5:
            max=pq.peek();
            cout << max<<" ";
            break;

        case 6:
            while (pq.the_size >= 0)
            {
                max=pq.extract_max();
                cout << max<<" ";
            }
            break;

        case 7:
            max= pq.pq_size();
            cout << max<<" ";
            break;

        }
        cout << endl;
    }

    return 0;
}