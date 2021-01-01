/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void leaf(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL)
            return;
        if(root->left==NULL and root->right==NULL)
        {
            vec.push_back(root->val);
        }
        leaf(root->left,vec);
        leaf(root->right,vec);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1;
        vector<int> v2;
        leaf(root1,v1);
        leaf(root2,v2);
        if(v1.size()!=v2.size())
            return false;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
                return false;
        }
        return true;
    }
};