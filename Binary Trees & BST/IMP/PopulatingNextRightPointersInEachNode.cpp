/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int height(Node* root)
    {
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    void connectUtil(Node* root,int level,Node *&prev)
    {
        if(!root)
            return;
        if(level==0)
        {
            if(prev)
            {
                prev->next = root;
                
            }
            prev = root;
            return;
        }
            connectUtil(root->left,level-1,prev);
            connectUtil(root->right,level-1,prev);
        
    }
    Node* connect(Node* root) {
        int h = height(root);
        // cout<<h;
        for(int i=1;i<h;i++)
        {
            Node *prev = NULL;
            connectUtil(root,i,prev);
        }
        return root;
    }
};