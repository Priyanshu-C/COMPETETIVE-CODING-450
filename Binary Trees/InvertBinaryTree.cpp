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

//Recursive Method

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
         swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
       
        return root;
    }
};

//Iterative Methods

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        
        queue <TreeNode*> Q;
        Q.push(root);
        TreeNode* temp;
        while(!Q.empty())
        {
            temp = Q.front();
            Q.pop();
            if(temp)
            {
                Q.push(temp->left);
                Q.push(temp->right);
                swap(temp->left,temp->right);
            }
        }
       
        return root;
    }
};