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

 // si


class Solution {
public:
    void zigzagLevelOrderUtil(TreeNode* root,vector<vector<int>> &ar,int level)
    {
        if(!root)
            return;
        if(ar.size()==level)
        {
            ar.push_back({root->val});
        }
        else if(level%2==0)
        {
            ar[level].insert(ar[level].end(),root->val);
        }
        else
        {
            ar[level].insert(ar[level].begin(),root->val);
        }
        zigzagLevelOrderUtil(root->left,ar,level+1);
        zigzagLevelOrderUtil(root->right,ar,level+1);
            
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ar;
        zigzagLevelOrderUtil(root,ar,0);
        return ar;
    }
};