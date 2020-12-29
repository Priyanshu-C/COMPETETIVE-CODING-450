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

// Serialize the tree while keeping the headnodes 

// [1,2,3,4,null,2,4,null,null,4]

// $$$ 4 $2 $1$$$ 4 $2 $3$ 4 $$$ 
// $$$ 4 $2 $3$ 4 $$ 
// $$ 4 $2 $ 
// $ 4 $ 


class Solution {
public:
        unordered_map<string,vector<TreeNode *>> MP;
        #define d(x) cout<<#x<<" "<<x<<endl;
        string dupSubUtil(TreeNode *root)
        {
            if(!root)
            return " ";

            string x = '$' + dupSubUtil(root->left);
             x  = x + to_string(root->val) ;
             x  = x + dupSubUtil(root->right)+  '$';
            
            
            MP[x].push_back(root);

            return x;
        }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ar;
        if(!root)
            return ar;
        dupSubUtil(root);
        for(auto i:MP)
        {
            if(i.second.size()>1) 
                ar.push_back(i.second[0]);
        }
        return ar;
    }
};