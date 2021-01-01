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

//Recursive 

class Solution {
public:
    
    void postorder(TreeNode* root,vector<int> &ar)
    {
        
        if(!root)
            return ;
        postorder(root->left,ar);
        postorder(root->right,ar);
        ar.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ar;
        postorder(root,ar);
        return ar;
        
    }
};

//Iterative 

// 1. Push root to first stack.
// 2. Loop while first stack is not empty
//    2.1 Pop a node from first stack and push it to second stack
//    2.2 Push left and right children of the popped node to first stack
// 3. Print contents of second stack

//TWO STACK METHOD

class Solution {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ar;
        if(!root)
            return ar;
    
        stack<TreeNode*> st1,st2;
        TreeNode* temp;
        
        st1.push(root);
        
        while(!st1.empty())
        {
            temp=st1.top();
            st2.push(temp);
            st1.pop();
            if(temp->left)
                st1.push(temp->left);
            if(temp->right)
                st1.push(temp->right);
        }
        while(!st2.empty())
        {
            ar.push_back(st2.top()->val);
            st2.pop();
        }
        
        
        return ar;
    }
};

// ONE STACK

