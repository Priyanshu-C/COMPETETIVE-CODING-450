/* C++ program to checks if a binary tree is max heap or not */
#include <bits/stdc++.h> 
  
using namespace std; 
   
/*  Tree node structure */

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
}; 
   
/* Helper function that allocates a new node */
struct Node *newNode(int k) 
{ 
    struct Node *node = new Node; 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
} 
  
bool checkValues(Node *root)
{
  if(!root->left or !root->right)
  return true;

  if(root->key > root->left->key and root->key > root->right->key)
  return checkValues(root->left) and checkValues(root->right);
  else
  return false;
}

bool checkCompleteness(Node *root,int level,int &H)
{
  if(!root)
  {
    //deb(level);
    if(level==H or level==H-1)
    return true;
    else return false;
  }
  return checkCompleteness(root->left,level+1,H) and checkCompleteness(root->right,level+1,H);

}

int height(Node* root)
{
  if(!root)
  return 0;
  return max(height(root->left),height(root->right)) + 1;
}
//  Function to check binary tree is a Heap or Not. 
bool isHeap(struct Node* root) 
{ 
    int H = height(root);
    //deb(H);
    if(!checkValues(root))
    return false;
    //deb(checkValues(root));
    if(!checkCompleteness(root,0,H))
    return false;
    return true;
} 
   
// Driver program 
int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(9); 
    root->right = newNode(8); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    root->left->left->left = newNode(3); 
    root->left->left->right = newNode(2); 
    root->left->right->left = newNode(1); 
   
    if (isHeap(root)) 
        cout << "Given binary tree is a Heap\n"; 
    else
        cout << "Given binary tree is not a Heap\n"; 
   
    return 0; 
} 