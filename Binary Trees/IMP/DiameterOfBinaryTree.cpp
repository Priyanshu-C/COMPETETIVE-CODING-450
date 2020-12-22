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

//Only using Height Function 

class Solution {
public:
    int Height(TreeNode *root)
    {
        if(!root)
            return 0;
        return max(Height(root->left),Height(root->right))+1;
    }
    
    void diameterT(TreeNode* root,int &D)
    {
        
        if(!root)
            return;
        int lh=Height(root->left);
        int rh=Height(root->right);
        
        D=max(D,lh+rh);
        diameterT(root->left,D);
        diameterT(root->right,D);
        
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int H=INT_MIN;
        diameterT(root,H);
        if(H==INT_MIN)
            return 0;
        return H;
    }
};

//Using recursive method

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
    #define d(x) cout<<#x<<" "<<x<<endl;
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        d(root->val);
        d(lh);
        d(rh);
        
        int m = lh+rh;
        return max(m,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        return m;
    }
};