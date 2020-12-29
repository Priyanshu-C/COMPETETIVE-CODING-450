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

//Better Approach is to simply initialize a root and keep assigning the values accordingly

    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = bstFromPreorder(A, root->val);
        root->right = bstFromPreorder(A, bound);
        return root;
    }


class Solution {
public:
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
         return new TreeNode(val);
        }
        if(root->val>val)
        {
            root->left = insertIntoBST(root->left,val);
        }
        if(root->val<val)
            root->right = insertIntoBST(root->right,val);
        return root;
    }

    // Simply take one node at a time and insert in the tree to get the BST
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     
        if(preorder.size()==0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size()==1)
            return root;
        for(int i=1;i<preorder.size();i++)
        {
            insertIntoBST(root,preorder[i]);
        }
        return root;
    }
};