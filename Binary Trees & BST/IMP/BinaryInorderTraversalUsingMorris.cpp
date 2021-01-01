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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ar;
        if(!root)
            return ar;
        
        TreeNode *curr = root,*pre;
        
        while(curr)
        {
            if(curr->left==NULL)
                {ar.push_back(curr->val);
                curr=curr->right;}
            else
            {
                pre=curr->left;
                while(pre->right and pre->right!=curr)
                    pre=pre->right;
                if(pre->right==NULL)
                {
                    pre->right = curr;
                    curr=curr->left;
                }
                else
                {
                    pre->right =NULL;
                    ar.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ar;
    }
};