#include <bits/stdc++.h>

using namespace std;

int depthOfBinaryTree(queue<char> path,int height)
{
    int depth=height;
    char leftChild = path.front();
    path.pop();                                     // Popping out the nodes once they are processed
    
    if ( leftChild == 'n' )
        depth = depthOfBinaryTree(path,height+1);   // Only traverse furthur if the child is a node
    
    char rightChild = path.front();
    path.pop();

    if ( rightChild == 'n' )
        depth = max(depth,depthOfBinaryTree(path,height+1));
    
    return depth;
}

int main(){
    
    string traversalPath;
    cin>>traversalPath;
    queue<char> path;

    for ( char ch : traversalPath )
        path.push(ch);
        
    path.pop();
    cout<<depthOfBinaryTree(path,1);                // 1 = 0 + 1  ( curent Height + 1 )
}