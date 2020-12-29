
/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

// The given root is the root of the Binary Tree
// Return the root of the generated BST

void change(Node *root,vector<int> &ar,int &i)
{
    if(!root)
    return;
    change(root->left,ar,i);
    root->data=ar[i++];
    change(root->right,ar,i);
}

void inorder(Node *root,vector<int> &ar)
{
    if(!root)
    return;
    inorder(root->left,ar);
    ar.push_back(root->data);
    inorder(root->right,ar);
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> ar;
    inorder(root,ar);
    int i=0;
    sort(ar.begin(),ar.end());
    change(root,ar,i);
    return root;
  
}