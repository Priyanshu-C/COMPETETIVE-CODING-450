// C++ program to replace every element with the
// least greater element on its right
#include <bits/stdc++.h>
using namespace std;
 
// A binary Tree node
struct Node
{
    int data;
    Node *left, *right;
};
 
// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
/* A utility function to insert a new node with
   given data in BST and find its successor */
void insert(Node*& node, int data, Node*& succ)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        node = newNode(data);
 
    // If key is smaller than root's key, go to left
    // subtree and set successor as current node
    if (data < node->data)
    {
        succ = node;
        insert(node->left, data, succ);
    }
 
    // go to right subtree
    else if (data > node->data)
        insert(node->right, data, succ);
}
 
// Function to replace every element with the
// least greater element on its right
void replace(vector<int> &ar, int n)
{
  Node* tree = NULL;
  Node* succ = NULL;
  for(int i=n-1;i>=0;i--)
  {
    succ=NULL;
    insert(tree,ar[i],succ);
    if(succ)
    ar[i]=succ->data;
    else
    ar[i]=-1;
  }

}
 
// Driver Program to test above functions
int main()
{
    vector<int> arr = { 8, 58, 71, 18, 31, 32, 63, 92,43, 3, 91, 93, 25, 80, 28 };
    int n = arr.size();
 
    replace(arr, n);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}