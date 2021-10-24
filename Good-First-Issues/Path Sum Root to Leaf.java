```

/*

Path Sum Root to Leaf

-----------------------

For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.

You need to create the function void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)

If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:

a. 2 3 4 4

b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.

The path is: 2 9 2(not a leaf)

*/

#include <bits/stdc++.h>

using namespace std;

 

// binary tree node

template <typename T>

class BinaryTreeNode {

    public : 

    T data;

    BinaryTreeNode<T> *left;

    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {

        this -> data = data;

        left = NULL;

        right = NULL;

    }

};

 

void printPath(const vector<int>& v, int i){

    for (int j = i; j < v.size(); j++)

        cout << v[j] << " ";

    cout << endl;

}

// Function to check if a given node is a leaf node or not

bool isLeaf(BinaryTreeNode<int>* node) {

    return (node->left == nullptr && node->right == nullptr);

}

// This function prints all paths that have sum k

void solve(BinaryTreeNode<int>* root, vector<int>& path, int k){

    if (!root) return;

 

    path.push_back(root->data);

    solve(root->left, path, k);

    solve(root->right, path, k);

    if(isLeaf(root)){

        int sum = 0;

        for (int j = path.size() - 1; j >= 0; j--) {

            sum += path[j];

            // If path sum is k, store the path

            if (sum == k) printPath(path, j);

        }

    }

    path.pop_back();

}

 

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k){

    vector<int> path;

    solve(root, path, k);

}

 

int main(){

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(2);

    root->left = new BinaryTreeNode<int>(3);

    root->left->left = new BinaryTreeNode<int>(4);

    root->left->left->left = new BinaryTreeNode<int>(4);

    root->left->right = new BinaryTreeNode<int>(8);

    root->right = new BinaryTreeNode<int>(9);

    root->right->right = new BinaryTreeNode<int>(2);

    root->right->right->left = new BinaryTreeNode<int>(6);

    

    int k = 13;

    rootToLeafPathsSumToK(root,k);

    

    return 0;

}

```
