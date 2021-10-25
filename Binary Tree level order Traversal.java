```

/*

102. Binary Tree Level Order Traversal

-----------------------------------------

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]

Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]

Output: [[1]]

Example 3:

Input: root = []

Output: []

*/

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}

 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 * };

 */

class Solution {

     public:

        vector<vector<int>> levelOrder(TreeNode* root) {

            if(root==NULL)

               return {};

            vector<vector<int>> ans; 

            queue<TreeNode*> q;

            q.push(root);

            TreeNode *temp;

            int len;

            while(!q.empty()){

               len=q.size();

		       vector<int> v;               for(int i=0;i<len;i++){

                    temp=q.front();

                    q.pop();

                    v.push_back(temp->val);

                   if(temp->left) q.push(temp->left);

                   if(temp->right) q.push(temp->right);

                }

		        ans.push_back(v);

            }

          return ans;

        }

     };

```
