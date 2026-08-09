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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        TreeNode* mover= root;
        TreeNode* par= nullptr;
        while(mover && mover->val!= key){
            par= mover;
            if(mover->val < key) mover= mover->right;
            else mover= mover-> left;
        }
        if(!mover) return root;
        if(!par) {
            if(!mover->left) return mover->right;
            if(!mover->right) return mover->left;

            TreeNode* temp = mover->right;

            while(temp->left) {
                temp = temp->left;
            }

            temp->left = mover->left;

            return mover->right;
        }
        if(mover->val < par->val && mover->right){
            par->left= mover->right;
            TreeNode* temp= mover->right;
            while(temp->left){
                temp= temp->left;
            }
            temp->left= mover->left;
        }
        else if(mover->val < par->val && !mover->right){
            par->left= mover->left;
        }
        else if(mover->val > par->val && mover->left){
            par->right= mover->left;
            TreeNode* temp= mover->left;
            while(temp->right){
                temp= temp->right;
            }
            temp->right= mover->right;
        }
        else if(mover->val > par->val && !mover->left){
            par->right= mover->right;
        }
        return root;
    }
};