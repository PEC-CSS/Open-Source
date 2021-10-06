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

void getVerticalOrder(BinaryTreeNode* root, int d, map<int, vector<int>> &order)
{
    // Base case
    if (root == NULL)
        return;
 
    // Store current node in map 'order'
    order[d].push_back(root->data);
 
    // Store nodes in left subtree
    getVerticalOrder(root->left, d-1, order);
 
    // Store nodes in right subtree
    getVerticalOrder(root->right, d+1, order);
}

void printVerticalorder(BinaryTreeNode* root)
{
    if (root == NULL)
        return;

    // Create a map and store vertical order in map using
    map < int,vector<int> > order;
    int d = 0;
    getVerticalOrder(root, d,order);
 
    // Traverse the map and print nodes at every horizontal
    map< int,vector<int> > :: iterator it;
    for (it=order.begin(); it!=order.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }

    return ;
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
    printVerticalorder(root);
    return 0;
    
}