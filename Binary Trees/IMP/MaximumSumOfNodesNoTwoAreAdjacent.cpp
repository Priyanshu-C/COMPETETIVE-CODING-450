// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <bits/stdc++.h>
using namespace std;
#define d(x) cout<<#x<<" "<<x<<endl;

/* A binary tree node structure */
struct node
{
    int data;
    struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
pair<int,int> getMaxSumUtil(node* root)
{
  if(!root)
  return {0,0};

  pair<int,int> TL;
  pair<int,int> TR;
  pair<int,int> T;
  
  TL = getMaxSumUtil(root->left);
  TR = getMaxSumUtil(root->right);

  //We consider this node 
  T.first = root->data + TL.second + TR.second;
  //Not consider this node 
  T.second = max(TL.first,TL.second) + max(TR.first,TR.second);

  return T;

}
int getMaxSum(node* root)
{
  pair<int,int> RES = getMaxSumUtil(root);
  return max(RES.first,RES.second);
}

//  Driver code to test above methods
int main()
{
    node* root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);

    cout << getMaxSum(root) << endl;
    return 0;
}