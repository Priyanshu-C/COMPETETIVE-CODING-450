#include <bits/stdc++.h> 
using namespace std; 
  

struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 

struct Node* getNode(int data) 
{ 
    struct Node *newNode = new Node; 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
}

void inorder(Node *root,vector<int> &ar)
{
  if(!root)
  return;

  inorder(root->left,ar);
  ar.push_back(root->data);
  inorder(root->right,ar);
}

void preorderTraversal(Node* root)
{
  if(!root)
  return;

  cout<<root->data<<" ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void preorder(Node* &root,vector<int> &ar,int &i)
{
  if(!root)
  return;

  root->data = ar[i++];
  preorder(root->left,ar,i);
  preorder(root->right,ar,i);
}

void convertToMinHeapUtil(Node *root) 
{ 
  vector<int> ar;
  inorder(root,ar);

  // for(int i:ar)
  // cout<<i<<" ";
  int i=0;
  preorder(root,ar,i);  
  return;
} 
  
// Driver program to test above 
int main() 
{ 
    // BST formation 
    struct Node *root = getNode(4); 
    root->left = getNode(2); 
    root->right = getNode(6); 
    root->left->left = getNode(1); 
    root->left->right = getNode(3); 
    root->right->left = getNode(5); 
    root->right->right = getNode(7); 
  
    convertToMinHeapUtil(root); 
    cout << "Preorder Traversal:" << endl; 
    preorderTraversal(root); 
  
    return 0; 
} 