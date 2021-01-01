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
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums,int L,int H)
    {
        if(L>H)
            return NULL;
        int M=(L+ H + 1)/2;
        TreeNode *root = new TreeNode(nums[M]);
        root->left = sortedArrayToBSTUtil(nums,L,M-1);
        root->right = sortedArrayToBSTUtil(nums,M+1,H);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums,0,nums.size()-1);a
    }
};