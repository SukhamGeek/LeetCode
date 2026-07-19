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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(root && (root->val>high || root->val<low)){
            if(root->val>high) root= root->left;
            else if(root->val < low) root= root->right;
        }
        if(!root) return root;
        TreeNode* mover= root;
        TreeNode *par= root;
        while(mover && mover->val!= low){
            if(mover->val>low){
                par= mover;
                mover= mover->left;
            }
            else{
                par->left= mover->right;
                mover= mover->right;
            } 
        }
        if(mover) mover->left= nullptr;
        mover= root;
        par= root;
        while(mover && mover->val!= high){
            if(mover->val>high){
                par->right= mover->left;
                mover= mover->left;
            }
            else{
                par= mover;
                mover= mover->right;
            } 
        }
        if(mover) mover->right= nullptr;
        return root;
    }
};