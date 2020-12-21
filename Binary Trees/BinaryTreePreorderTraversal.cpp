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
    
    void preorder(TreeNode* root,vector<int> &ar)
    {
        
        if(!root)
            return ;
        
        ar.push_back(root->val);
        preorder(root->left,ar);
        preorder(root->right,ar);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ar;
        preorder(root,ar);
        return ar;
        
    }
};

//Iterative Approach

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ar;
        if(!root)
            return ar;
        
        stack<TreeNode*> st;
        TreeNode *curr ;
        st.push(root);
        
        while(!st.empty())
        {
            curr=st.top();
            st.pop();
            ar.push_back(curr->val);
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return ar;
    }
};