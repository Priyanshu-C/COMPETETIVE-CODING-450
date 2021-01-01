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
    
    void rightSide(TreeNode* root,int l,vector<int> &ar)
    {
        if(!root)
            return;
        if(ar.size()<=l)
        {
            ar.push_back(root->val);
        }
        rightSide(root->right,l+1,ar);
        rightSide(root->left,l+1,ar);
            return;
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ar;
        rightSide(root,0,ar);
            return ar;
        
    }
};