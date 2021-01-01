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

//Very smart approach simply exchange the node with min value on the right side, if it's not there simply change it with right or left tree path.

class Solution {
public:
    
    TreeNode* minNode(TreeNode* root)
    {
        while(root->left)
        {
            root=root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val<key)
        {
            root->right = deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
            root->left = deleteNode(root->left,key);
        }
        else if(root->val==key)
        {
          //if both are NULL simply return NULL
            if(!root->left and !root->right)
                return NULL;
          //if left is NULL we can simply replace it with the right tree
            if(root->left==NULL)
                return root->right;
          //if right is NULL we can simply replace it with the left tree
            else if(root->right==NULL)
                return root->left;
            else {
              //Find the min Node on the right, and simply change the value of the current node and delete the min Node.
                TreeNode *temp = minNode(root->right);
                //cout<<"/////"<<temp->val<<"/////";
                deleteNode(root,temp->val);
                root->val=temp->val;
                 }
        }
        return root;
    }
};