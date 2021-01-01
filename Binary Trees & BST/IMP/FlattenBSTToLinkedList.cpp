#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
   TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



    TreeNode* prev = NULL;
    void flattenUtil(TreeNode* &root) {
        if(!root)
            return;
        flattenUtil(root->left);
        if(!prev)
        {
            prev=root;
        }
        else {
        prev->right=root;
        prev->left=NULL;
        prev=root;
        }
        flattenUtil(root->right);
        return;
    }
    void flatten(TreeNode* root) {
        flattenUtil(root);
        root=prev;
        return;
    }


int main() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(9);
  root->left->left = new TreeNode(8);
  root->left->left->left = new TreeNode(7);
  root->right = new TreeNode(11);
  


  std::cout << "Hello World!\n";
}