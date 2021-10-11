/*
You are given the size, inorder and preorder input arrays of a binary tree. You are supposed to build the binary tree and print it in postorder format.
Note: Assume that the tree contains unique values and hence no value is repeated.

Input Format:
The first line contains the size of the arrays.
The second line contains the inorder array.
The third line contains the preorder array.

Output Format:
A single line containing the postorder format of the Binary Tree.

Sample Input:
9
4 2 5 1 8 6 9 3 7
1 2 4 5 3 6 8 9 7

Sample Output:
4 5 2 8 9 6 7 3 1
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printPostOrder(Node *root){
	if(root==NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

class Solution{
    public:
    int idx =0;
    unordered_map<int,int>m;
    Node*search(int pre[],int in[],int l,int r){
        if(l>r) return NULL;
        Node* res = new Node(pre[idx++]);
        if(l==r) return res;
        int mid = m[res->data];
        res->left=search(pre,in,l,mid-1);
        res->right=search(pre,in,mid+1,r);   
        return res;
    }
    Node* buildTree(int in[],int pre[], int n){
        m.clear();
        for(int i=0;i<n;i++) m[in[i]]=i;
        return search(pre,in,0,n-1);
    }
};

int main(){
	int n;
	cin>>n;
		
	int inorder[n], preorder[n];
	for(int i=0; i<n; i++) cin>> inorder[i];
	for(int i=0; i<n; i++) cin>> preorder[i];
	Solution obj;
	Node *root = obj.buildTree(inorder, preorder, n);
	printPostOrder(root);
	cout<< endl;
}
