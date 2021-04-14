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
    int maxLevel=0;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    void DLTU(TreeNode* root,int &sum,int level)
    {
        if(!root)
            return;
        if(level==maxLevel-1)
            sum+=root->val;
        DLTU(root->left,sum,level+1);
        DLTU(root->right,sum,level+1);
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        maxLevel = height(root);
        DLTU(root,sum,0);
        return sum;
    }
};