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
    #define d(x) cout<<#x<<" "<<x<<" "<<endl;
    int findTiltUtil(TreeNode* root,int &sum)
    {
        if(!root)
            return 0;
        if(!root->left and !root->right)
            return root->val;
        int left = findTiltUtil(root->left,sum);
        int right = findTiltUtil(root->right,sum);
        // d(left);
        // d(right);
        sum+=abs(right-left);
        return left+right+root->val;
    }
    
    int findTilt(TreeNode* root) {
        int sum =0;
        findTiltUtil(root,sum);
        return sum;
    }
};