#include <bits/stdc++.h>

using namespace std;


class TreeNode {
public:
    int data;
    vector<TreeNode *> children;

    TreeNode(int data)
    {
        this->data = data;
    }
};


void level_wise_order(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        cout << node->data << " ";

        for (auto child : node->children)
            q.push(child);
    }
    cout << '\n';
}


int main()
{
    TreeNode root(0);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);

    root.children.push_back(node1);
    root.children.push_back(node4);
    node1->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node5);
    node4->children.push_back(node6);
    node4->children.push_back(node7);

    /* Tree Structure

            0
          /   \
        1      4
      / | \   /  \
     2  3  5 6    7

    */

    level_wise_order(&root);

    return 0;
}