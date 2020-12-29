#include <iostream> 
using namespace std; 
  
// BST Node 
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// This function finds predecessor and successor of key in BST. 
// It sets pre and suc as predecessor and successor respectively 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    
    if(!root)
    return ;

    if(root->key>key)
        {    
        suc=root;
        findPreSuc(root->left,pre,suc,key);
        }
    else if(root->key<key)
        {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
        }
    else if(root->key==key)
    {
      if(!root->left and !root->right)
      return;
      if(root->left)
      {
        Node *temp = root->left;
        while(temp->right)
        temp=temp->right;
        pre=temp;
      }
      if(root->right)
      {
        Node *temp = root->right;
        while(temp->left)
        temp=temp->left;
        suc=temp;
      }
      return;
    }

} 
  
// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
    Node *temp =  new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
    return node; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int key = 65;    //Key to be searched in BST 
  
   /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
  
    Node* pre = NULL, *suc = NULL; 
  
    findPreSuc(root, pre, suc, key); 
    if (pre != NULL) 
      cout << "Predecessor is " << pre->key << endl; 
    else
      cout << "No Predecessor"; 
  
    if (suc != NULL) 
      cout << "Successor is " << suc->key; 
    else
      cout << "No Successor"; 
    return 0; 
} 