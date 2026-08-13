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
    bool isValidBST(TreeNode* root) {
        bool b= false;
        bool left= true;
        bool right= true;
        if((root->val== INT_MAX && root->right) || (root->val== INT_MIN && root->left)) return false;
        if(root->left && root->val!= INT_MIN) left= helper(root->left, INT_MIN, root->val- 1);  
        b=true;     
        if(root->right && root->val!= INT_MAX) right= helper(root->right, root->val +1, INT_MAX); 
        if(left && right) return true;
        return false;      
    }
    bool helper(TreeNode* root, int l, int r) {
        if(!root) return true;
        if((root->val== INT_MAX && root->right) || (root->val== INT_MIN && root->left)) return false;
        if((root->val> r || root->val<l)) return false;
        bool left= true; 
        bool right = true;
        if(root->val!= INT_MIN) left= helper(root->left, l, root->val -1);       
        if(root->val!= INT_MAX) right= helper(root->right, root->val+ 1, r);  
        if(left && right) return true;
        return false;     
    }
};