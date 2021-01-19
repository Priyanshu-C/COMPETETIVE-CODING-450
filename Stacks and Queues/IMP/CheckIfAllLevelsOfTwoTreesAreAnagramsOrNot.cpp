#include <bits/stdc++.h> 
using namespace std; 
  
// A Binary Tree Node 
struct Node 
{ 
    struct Node *left, *right; 
    int data; 
};

Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

bool compArray(vector<int> &A,vector<int> &B)
{
  if(A.size()!=B.size())
  return false;
  for(int i=0;i<A.size();i++)
  {
    if(A[i]!=B[i])
    return false;
  }
  return true;
}

bool areAnagrams(Node *root1, Node *root2)
{
  queue<Node*> Q1,Q2;
  Q1.push(root1);
  Q2.push(root2);
  vector<int> A;
  vector<int> B;

  while(!Q1.empty() and !Q2.empty())
  {
    int s1=Q1.size();
    int s2=Q2.size();
    if(s1!=s2)
    return false;

    while(s1--)
    {
      if(Q1.front()->left)
      Q1.push(Q1.front()->left);
      if(Q1.front()->right)
      Q1.push(Q1.front()->right);

      if(Q2.front()->left)
      Q2.push(Q2.front()->left);
      if(Q2.front()->right)
      Q2.push(Q2.front()->right);

      A.push_back(Q1.front()->data);
      Q1.pop();
      B.push_back(Q2.front()->data);
      Q2.pop();
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    if(!compArray(A,B))
    return false;
    A.clear();
    B.clear();
  }
  return true;
}


int main() 
{ 
    // Constructing both the trees. 
    struct Node* root1 = newNode(1); 
    root1->left = newNode(3); 
    root1->right = newNode(2); 
    root1->right->left = newNode(5); 
    root1->right->right = newNode(4); 
  
    struct Node* root2 = newNode(1); 
    root2->left = newNode(2); 
    root2->right = newNode(3); 
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5); 
  
    areAnagrams(root1, root2)? cout << "Yes" : cout << "No"; 
    return 0; 
}