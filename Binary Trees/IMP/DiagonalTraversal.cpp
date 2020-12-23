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

//Basicall when going right of the tree you stay on the same diognal so,simply append those nodes on the same level.

class Solution {
public:
    void diognalutil(TreeNode* root,vector<vector<int>> &ar,int level)
    {
        if(!root)
            return;
        if(ar.size()==level)
            ar.push_back({root->val});
        else
            ar[level].push_back(root->val);
        diognalutil(root->left,ar,level+1);
        diognalutil(root->right,ar,level);
            
    }
    
    vector<vector<int>> DiognalTraversal(TreeNode* root) {
        vector<vector<int>> ar;
        diognalutil(root,ar,0);
        return ar;
    }
};