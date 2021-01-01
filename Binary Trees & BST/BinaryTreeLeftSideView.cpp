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
    
    void leftSide(TreeNode* root,int l,vector<int> &ar)
    {
        if(!root)
            return;
        if(ar.size()<=l)
        {
            ar.push_back(root->val);
        }
        leftSide(root->left,l+1,ar);
        leftSide(root->right,l+1,ar);
            return;
        
    }
    
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ar;
        leftSide(root,0,ar);
            return ar;
        
    }
};