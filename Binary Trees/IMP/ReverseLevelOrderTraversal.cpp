
class Solution {
public:
     int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    void levelT(TreeNode* root,vector<vector<int>> &ar,int level)
    {
      if(!root)
      return;
      if(root)
      ar[level].push_back(root->val);
        if(root->left)
      levelT(root->left,ar,level+1);
        if(root->right)
      levelT(root->right,ar,level+1);
      return;
    }
    

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int H=maxDepth(root);
        vector<vector<int>> ar(H);
        levelT(root,ar,0);
        reverse(ar.begin(),ar.end());
        return ar;
    }
};