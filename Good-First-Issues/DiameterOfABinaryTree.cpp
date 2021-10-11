/*
CPP Program find max diameter of a binary tree

The diameter of a tree (sometimes called the width) is the
number of nodes on the longest path between two end nodes 

Author: Saurabh Singh  
*/

#include <bits/stdc++.h>

using namespace std;

//structure of a tree node - data, left and right pointer for left and right subtree
struct Node {
  int data;
  Node * left;
  Node * right;
};

Node * newNode(int data) {
  // Create a new node with passed data value and left/ right subtree as null
  Node * node = new Node;
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return node;
}

/*
function to calculate the max diameter using maxHeight.
Max Diameter is set in the argument passed as address.
Funtion returns the max height of the subtree below that node
*/
int calculateMaxHeight(Node * root, int & maxDia) {
  if (root == NULL) {
    return 0;
  }
  int lHeight = calculateMaxHeight(root -> left, maxDia);
  int rHeight = calculateMaxHeight(root -> right, maxDia);

  /* Max diameter would be max of current max diamter or 
  left subtree height + right subtree height + 1(self node)
  */
  maxDia = max(maxDia, lHeight + rHeight + 1);

  return 1 + max(lHeight, rHeight);
}

// Function to return max diameter of the tree
int calculateDiameter(Node * root) {
  if (root == NULL) {
    return 0;
  }
  int maxDia = -1;
  calculateMaxHeight(root, maxDia);
  return maxDia;
}

int main() {
  Node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  printf("Diameter of the given binary tree is %d\n", calculateDiameter(root));

  return 0;
}
