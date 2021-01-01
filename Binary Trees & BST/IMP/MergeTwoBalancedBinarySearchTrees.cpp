
#include<bits/stdc++.h> 
using namespace std; 
#define d(x) cout<<#x<<" "<<x<<endl;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  

node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return(Node);  
}  

void printInorder(node* node)  
{  
    if (node == NULL)  
        return;  
  
    printInorder(node->left);  
  
    cout << node->data << " ";  

    printInorder(node->right);  
}  

void storeInorder(node* node, vector<int> &ar)  
{  

  if(!node)
  return;
  storeInorder(node->left,ar);
  ar.push_back(node->data);
  storeInorder(node->right,ar);

}  

vector<int> merge(vector<int> &A,vector<int> &B)  
{  

A.insert(A.end(),B.begin(),B.end());
int n = A.size();
int GAP = ceil(n/2);
while(GAP)
{
  //d(GAP);
  for(int i=0;i+GAP<n;i++)
  {
    if(A[i]>A[GAP+i])
    swap(A[i],A[GAP+i]);
  }

  // for(int i:A) //for i in A: // for var i in A {} // for
  // cout<<i<<" ";
  // cout<<endl;

  GAP/=2;
}
return A;
}  

node* mergeBSTUsingVector(vector<int> A,int L,int H)
{
  if(L>H)
  return NULL;
  int M = (L+H)/2;
  node* root= newNode(A[M]);
  root->left= mergeBSTUsingVector(A,L,M-1);
  root->right= mergeBSTUsingVector(A,M+1,H);
  return root;
}

node* mergeTrees(node *root1, node *root2, int m, int n)  
{  
   vector<int> A;
   vector<int> B;
   storeInorder(root1,A);
   storeInorder(root2,B);
   vector<int> mergedArray = merge(A,B);

  //  for(int i:A)
  //  cout<<i<<" ";
  //  return root1;

   return mergeBSTUsingVector(A,0,A.size()-1);

}  
   
  
/* Driver code*/
int main()  
{  
    /* Create following tree as first balanced BST  
        100  
        / \  
        50 300  
    / \  
    20 70  
    */
    node *root1 = newNode(100);  
    root1->left     = newNode(50);  
    root1->right = newNode(300);  
    root1->left->left = newNode(20);  
    root1->left->right = newNode(70);  
  
    /* Create following tree as second balanced BST  
            80  
        / \  
        40 120  
    */
    node *root2 = newNode(80);  
    root2->left     = newNode(40);  
    root2->right = newNode(120);  
  
    node *mergedTree = mergeTrees(root1, root2, 5, 3);  
  
    cout << "Following is Inorder traversal of the merged tree \n";  
    printInorder(mergedTree);  
  
    return 0;  
}  
  
// This code is contributed by rathbhupendra 