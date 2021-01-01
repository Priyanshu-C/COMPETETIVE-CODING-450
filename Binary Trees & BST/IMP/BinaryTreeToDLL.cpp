//https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/

// A C++ program for in-place conversion of Binary Tree to DLL 
#include <iostream> 
using namespace std; 
  
/* A binary tree node has data, and left and right pointers */
struct node 
{ 
    int data; 
    node* left; 
    node* right; 
}; 

void BinaryTree2DoubleLinkedList(node *root,node *&head,node *&prev)
{
  if(!root)
  return;

  BinaryTree2DoubleLinkedList(root->left,head,prev);

  if(prev==NULL)
  {
    head=root;
  }
  else 
  {
    root->left=prev;
    prev->right=root;
  }
  prev=root;
  BinaryTree2DoubleLinkedList(root->right,head,prev);
}


node* newNode(int data) 
{ 
    node* new_node = new node; 
    new_node->data = data; 
    new_node->left = new_node->right = NULL; 
    return (new_node); 
} 
  
/* Function to print nodes in a given doubly linked list */
void printList(node *node) 
{ 
    while (node!=NULL) 
    { 
        cout << node->data << " "; 
        node = node->right; 
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    // Let us create the tree shown in above diagram 
    node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    // Convert to DLL 
    node *head = NULL; 
    node *prev = NULL; 
    BinaryTree2DoubleLinkedList(root, head,prev); 
  
    // Print the converted list 
    printList(head); 
  
    return 0; 
} 