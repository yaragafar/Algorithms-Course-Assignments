#include <vector>
#include "my_tree.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int size;
    int num_ops;

    MyTree tree=  MyTree(0);
    MyTree* root = NULL;

    //cout << "Enter size of your BST and number of operations to perform: ";
    cin >> size;
    cin >> num_ops;

   // cout << "Enter the elements to be inserted in the tree: ";
    vector<int> elements(size, 0);
    for(int i=0;i<size;i++)
    {cin >> elements[i];
    }
    sort(elements.begin(), elements.end());
    root = tree.insertforVector(elements, 0, elements.size() - 1);


    for (int i = 0; i < num_ops; i++)
    {
        vector<int> op(2,0);
        //cout << "Choose an operation to be performed: " << endl;
        //cout << "1.insert an element in the tree" << endl;
        //cout << "2.serach for an element in the tree" << endl;
        //cout << "3.1.in-order recursive" << endl;
        //cout << "3.2.in-order iterative" << endl;
        //cout << "4.1.pre-order recursive" << endl;
        //cout << "4.2.pre-order recursive" << endl;
        //cout << "5.1.post-order recursive" << endl;
        //cout << "5.2.post-order recursive" << endl;
        //cout << "6.breadth traversal" << endl;
        //cout << "7.print size of the tree" << endl;
        //cout << "8.print a 2D representation of the tree" << endl;
        //cout << "9.remove an element from the tree" << endl;

        cin >> op[0];

        switch (op[0])
        {
        case 1:
            cin >> op[1];
            tree.insert(root, op[1]);
            //cout << endl;
            break;
        
        case 2:
            bool is_there;
            cin >> op[1];
            is_there=tree.search(root, op[1]);
            //if (is_there) { cout << "True"<<endl; }
            //else{ cout << "False" << endl; }
            cout << is_there<<" ";
            break;

        case 3:
            cin >> op[1];
            switch (op[1])
            {
            case 1:
               // cout << "recursive inorder : ";
                tree.inorder_rec(root);
                break;
            case 2:
                //cout << "iterative inorder: ";
                tree.inorder_it(root);
                break;
            }
            break;

        case 4:
            cin >> op[1];
            switch (op[1])
            {
            case 1:
                //cout << "recursive pre-order : ";
                tree.preorder_rec(root);
                //cout << endl;
                break;
            case 2:
                //cout << "iterative pre-order: ";
                tree.preorder_it(root);
                //cout << endl;
                break;
            }
            break;


        case 5:
            cin >> op[1];
            switch (op[1])
            {
            case 1:
                //cout << "recursive post-order : ";
                tree.postorder_rec(root);
                //cout << endl;
                break;
          
            case 2:
                //cout << "iterative post-order: ";
                tree.postorder_it(root);
                //cout << endl;
                break;
            
            case 3:
                //cout << "iterative post-order: ";
                tree.postorder_it(root);
                //cout << endl;
                break;


            }
            break;

        case 6:
            //cout << "breadth traversal: ";
            tree.breadth_traversal(root);
            //cout << endl;
            break;

        case 7:
            int tree_size;
            tree_size = tree.size(root);
            cout << tree_size<<" ";
            break;


        case 8:
            tree.print_tree(root, 10);
            break;


        case 9:
            cin >> op[1];
            tree.remove(root, op[1]);
            break;
        }
        cout << endl;
    }

    return 0;
}

