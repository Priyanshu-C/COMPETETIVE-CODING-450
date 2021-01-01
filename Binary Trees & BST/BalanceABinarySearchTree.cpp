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
    
    TreeNode* makeBalancedBST(vector<int> &ar,int L,int H)
    {
        if(L>H)
            return NULL;
        int M=(L+H)/2;
        TreeNode *root =  new TreeNode(ar[M]);
        root->left = makeBalancedBST(ar,L,M-1);
        root->right = makeBalancedBST(ar,M+1,H);
        return root;
    }
    
    void inorder(TreeNode* root,vector<int> &ar)
    {
        if(!root)
            return;
        inorder(root->left,ar);
        ar.push_back(root->val);
        inorder(root->right,ar);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> ar;
        inorder(root,ar);
        return makeBalancedBST(ar,0,ar.size()-1);
        
    }
};