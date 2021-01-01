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

// Simple approach go all the way to the leaf while pushing values in an array and then see while adding the sum how many of them is equal to the required sum.


class Solution {
public:
    int count = 0 ;
    void pathSumUtil(TreeNode* root, int sum,vector<int> &ar)
    {
        if(!root)
            return;
        
        ar.push_back(root->val);
        pathSumUtil(root->left,sum,ar);
        pathSumUtil(root->right,sum,ar);
        int intitSum = 0;
        for(int i=ar.size()-1;i>=0;i--)
        {
            intitSum+=ar[i];
            if(intitSum==sum)
                count++;
        }
        //We need to pop this since in the next path this node won't be included.
        ar.pop_back();
        return;
    }
    
    int pathSum(TreeNode* root, int sum) {
        vector<int> ar;
        pathSumUtil(root,sum,ar);
        return count;
    }
};