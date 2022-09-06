#pragma once
#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MyTree {

private:

public:
    int key;
    MyTree* left;
    MyTree* right;

    //default constructor
    MyTree() {
        key = 0;
        left = NULL;
        right = NULL;
    }

    MyTree(vector<int> elements) {}

    //parametarized constructor
    MyTree(int k) {
        key = k;
        left = NULL;
        right = NULL;
    }

    MyTree* insertforVector(vector<int> vec, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        MyTree* pr = newNode(vec[mid]);
        pr->left = insertforVector(vec, start, mid - 1);
        pr->right = insertforVector(vec, mid + 1, end);
        return pr;
    }

    MyTree* newNode(int data)
    {
        MyTree* temp = new MyTree;

        temp->key = data;

        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
    //MyTree(vector<int> elements) {
    //    sort(elements.begin(), elements.end());
    //    root = insertforVector(elements, 0, elements.size() - 1);
    //}
    //MyTree* insertforVector(vector<int> vec, int start, int end)
    //{
    //    if (start > end)
    //        return NULL;
    //    int mid = (start + end) / 2;
    //    MyTree* pr = new MyTree(vec[mid]);
    //    pr->left = insertforVector(vec, start, mid - 1);
    //    pr->right = insertforVector(vec, mid + 1, end);
    //    return pr;
    //}




    bool search(MyTree* node, int key) {

        if (node)
        {
            if (node->key == key)
            {
                return true;
            }
            else if (key < node->key)
                return search(node->left, key);
            else
                return search(node->right, key);
        }
        else return false;
    }

    MyTree* insert(MyTree* node, int key) {

        if (node == NULL)
        {
            return new MyTree(key);
        }

        if (key > node->key)
        {
            node->right = insert(node->right, key);
        }

        else

        {
            node->left = insert(node->left, key);
        }

        return node;
    }


    //LNR
    void inorder_rec(MyTree* node) {

        if (node != NULL)
        {
            inorder_rec(node->left);
            cout << node->key << " ";
            inorder_rec(node->right);
        }
    }

    //NLR
    void preorder_rec(MyTree* node) {

        if (node != NULL)

        {
            cout << node->key << " ";
            preorder_rec(node->left);
            preorder_rec(node->right);
        }
    }

    //LRN
    void postorder_rec(MyTree* node) {
        if (node != NULL)

        {
            postorder_rec(node->left);
            postorder_rec(node->right);
            cout << node->key << " ";
        }
    }


    void inorder_it(MyTree* root)
    {
        stack<MyTree*> s;
        while (root != NULL || s.empty() == false)
        {

            while (root != NULL)
            {

                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            cout << root->key << " ";

            root = root->right;

        } 
    }

    void preorder_it(MyTree* root)
    {
        if (root == NULL)
            return;

        stack<MyTree*> s;
        s.push(root);

        while (s.empty() == false) {
            MyTree* root = s.top();
            cout << root->key << " ";
            s.pop();

            if (root->right)
                s.push(root->right);
            if (root->left)
                s.push(root->left);
        }
    }

    void postorder_it(MyTree* root) {
        stack<MyTree*> s;
        while (true) {
            while (root != NULL) {
                s.push(root);
                s.push(root);
                root = root->left;
            }
            if (s.empty()) return;
            root = s.top();
            s.pop();
            if (!s.empty() && s.top() == root)
                root = root->right;

            else {

                cout << root->key << " ";
                root = NULL;
            }
        }
    }

    void breadth_traversal(MyTree* root) {
        if (root == NULL) return;
        queue<MyTree*> q;
        q.push(root);
        while (!q.empty())
        {
            MyTree* root = q.front();
            cout << root->key << " ";
            q.pop();

            // Enqueue left child 
            if (root->left != NULL)
                q.push(root->left);

            //Enqueue right child 
            if (root->right != NULL)
                q.push(root->right);
        }
    }

    //prints size of a tree given its root
    int size(MyTree* node) {
        if (node == NULL)
        {
            return 0;
        }
        else { return 1 + size(node->right) + size(node->left); }
    }

    // prints a 2D representation of our tree
    void print_tree(MyTree* r, int space)
    {
        if (r == NULL)
        {
            return;
        }

        space += 10;
        print_tree(r->right, space);
        cout << endl;
        for (int i = 10; i < space; i++)
        {
            cout << " ";
        }
        cout << r->key << "\n";
        print_tree(r->left, space);
    }

    // removes a node if it exists in a tree given its key
    MyTree* remove(MyTree* root, int k)
    {
        if (root == NULL)
            return root;
        //If root->data is greater than k then we delete the root's subtree
        if (root->key > k) {
            root->left = remove(root->left, k);
            return root;
        }
        else if (root->key < k) {
            root->right = remove(root->right, k);
            return root;
        }


        // If one of the children is empty 
        if (root->left == NULL) {
            MyTree* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            MyTree* temp = root->left;
            delete root;
            return temp;
        }
        else {
            MyTree* Parent = root;
            // Find successor of the node
            MyTree* succ = root->right;
            while (succ->left != NULL) {
                Parent = succ;
                succ = succ->left;
            }

            if (Parent != root)
                Parent->left = succ->right;
            else
                Parent->right = succ->right;

            // Copy Successor Data  
            root->key = succ->key;

            // Delete Successor and return root 
            delete succ;
            return root;
        }
    }
};





#endif