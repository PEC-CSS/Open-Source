#include <bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;

class BinaryTreeNode {
    public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(){
        data=0;
        left=right=NULL;
    }
};

BinaryTreeNode* newnode(int data){
    BinaryTreeNode* temp = new BinaryTreeNode;
    temp->data = data;
    return temp;
}

// left view of a binary tree.
void leftViewUtil(BinaryTreeNode *root, int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }

    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
     
}

void leftView(BinaryTreeNode *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

BinaryTreeNode* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
    return NULL;
    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
    ip.push_back(str);

    // Create the root of the tree
    BinaryTreeNode* root = newnode (stoi(ip[0]));
    // Push the root to the queue
    queue<BinaryTreeNode*> queue;
    queue.push(root);
    // Starting from the second element
    int i = 1;
    while( ! queue. empty() && i < ip.size()) {
    // Get and remove the front of the queue
    BinaryTreeNode* currNode = queue. front();
    queue.pop();
    // Get the current node's value from the string
    string currval = ip[i];
    // If the left child is not null
    if(currval != "N") {
    // Create the left child for the current node
    currNode->left = newnode (stoi(currval));
    // Push it to the queue
    queue.push(currNode->left);
    }
    // For the right child
    i++;
    if(i >= ip.size())
    break;
    currval = ip[i];
    // If the right child is not null
    if(currval != "N") {
    // Create the right child for the current node
    currNode->right = newnode(stoi(currval));
    // Push it to the queue
    queue.push(currNode->right);
    }
    i++;
    }
    return root;
}


int main(){
    cout<<"Enter the value of nodes in level order where numbers denote node values, and character N denotes Null child:\n";
    string s;
    getline(cin, s);
    BinaryTreeNode* root = buildTree(s);
    leftView(root);
    return 0;
    
}