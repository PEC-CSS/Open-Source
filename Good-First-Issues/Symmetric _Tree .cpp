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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode *P,*Q;
         if(root ->left==NULL&&root->right==NULL)
            return true;
        if(root ->left==NULL||root->right==NULL)
            return false;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty( )){
            P=q.front( );
            q.pop( );
            Q=q.front( );
            q.pop( );
            if(P->val!=Q->val)
                return false;
            if(P->left!=NULL&&Q->right!=NULL){
                q.push(P->left);
                q.push(Q->right);
                
            }
             if(P->right!=NULL &&Q->left!=NULL){
                 q.push(P->right);
                 q.push(Q->left);
             }
            if(P->left!=NULL&&Q->right==NULL ||Q->left!=NULL&&P->right==NULL||P->left==NULL&&Q->right!=NULL||Q->left==NULL&&P->right!=NULL)
                return false;
        }
        return true;
    }
};