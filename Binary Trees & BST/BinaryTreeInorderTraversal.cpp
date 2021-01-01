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

//Recursive Approach

class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &ar)
    {
        
        if(!root)
            return ;
        inorder(root->left,ar);
        ar.push_back(root->val);
        inorder(root->right,ar);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ar;
        inorder(root,ar);
        return ar;
        
    }
};

//Iterative Approach

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ar;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        while(curr or !st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ar.push_back(curr->val);
            curr=curr->right;
        }
        return ar;
    }
};



