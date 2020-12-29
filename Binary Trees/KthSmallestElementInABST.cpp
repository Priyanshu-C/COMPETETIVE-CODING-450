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
    
    void inorder(TreeNode* root,vector<int> &ar,int &k)
    {
        if(ar.size()==k)
            return;
        if(!root)
            return;
        inorder(root->left,ar, k);
        ar.push_back(root->val);
        inorder(root->right,ar, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ar;
        inorder(root,ar,k);
        for(int i:ar)
            cout<<i<<" ";
        if(k>ar.size())
            return -1;
        return ar[k-1];
    }
};