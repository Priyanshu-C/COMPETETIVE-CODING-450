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
    
    bool isValidBSTUtil(TreeNode* root,long low,long high)
    {
        if(!root)
            return true;
        if(root->val<=low or root->val>=high)
            return false;
        return isValidBSTUtil(root->left,low,root->val) and isValidBSTUtil(root->right,root->val,high);
    }
    
    bool isValidBST(TreeNode* root) {
        
       return isValidBSTUtil(root,LONG_MIN,LONG_MAX);
    }
};