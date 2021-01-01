/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Find a node whose value is in between both the nodes, that will be the LCA of BST simple
// Navigation through the tree is simple by follwoing the greater or less poslicy

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root->val > p->val and root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(root->val < p->val and root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    
    }
};