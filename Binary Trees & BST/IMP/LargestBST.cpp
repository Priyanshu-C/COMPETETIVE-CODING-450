// C++ program of above approach 
#include<bits/stdc++.h>  
#define d(x) cout<<#x<<" "<<x<<" "<<endl;
using namespace std;  
  

struct MinMax  
{  
    public: 
    bool Valid;
    int L;    
    int H;
    int S;

    MinMax() 
    { 
        this->Valid = 1; 
        this->L = INT_MAX; 
        this->H = INT_MIN; 
        this->S = 0;
    } 

    MinMax(bool valid,int L,int H,int S) 
    { 
        this->Valid = valid; 
        this->L = L; 
        this->H = H; 
        this->S = S;
    } 
}; 

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
      
    /* Constructor that allocates  
    a new node with the given data  
    and NULL left and right pointers. */
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
          
    } 
};  


MinMax* largestBSTUtil(node* root)
{
  // cout<<"X";
  if(!root)
  return new MinMax();

  MinMax *left;
  MinMax *right;
  MinMax *mainRoot = new MinMax();

    left = largestBSTUtil(root->left);
    right = largestBSTUtil(root->right);
 
  
    d(left->Valid);
    d(left->L);
    d(left->H);
    d(left->S);
    cout<<endl;
    d(right->Valid);
    d(right->L);
    d(right->H);
    d(right->S);
    cout<<endl;
  
   if(left->Valid == false || right->Valid == false || (left->H > root->data || right->L < root->data)){
            mainRoot->Valid = false;
            mainRoot->S = max(left->S, right->S);
            return mainRoot;
        }

        mainRoot->Valid = 1;
        mainRoot->S = left->S + right->S + 1;
        mainRoot->L = root->left != NULL ? left->L : root->data;
        mainRoot->H = root->right != NULL ? right->H : root->data;
        return mainRoot;

}
  

int largestBST(node* root)  
{  
  MinMax *RES = largestBSTUtil(root);
  // d(RES->Valid);
  // d(RES->L);
  // d(RES->H);
  // d(RES->S);
  return RES->S;

}  

  

int main()  
{  
        /* Let us construct the following Tree  
            50  
          /   \  
        10    60  
        / \   / \  
      5   20 55  70  
             /  / \  
          45   65  80  
    */
      
    node *root = new node(50);  
    root->left = new node(10);  
    root->right = new node(60);  
    root->left->left = new node(5);  
    root->left->right = new node(20);  
    root->right->left = new node(55);  
    root->right->left->left = new node(45);  
    root->right->right = new node(70);  
    root->right->right->left = new node(65);  
    root->right->right->right = new node(80);  
      
    /* The complete tree is not BST  
    as 45 is in right subtree of 50.  
    The following subtree is the largest BST  
            60  
        / \  
        55 70  
    / / \  
    45 65 80  
    */
    cout<<" Size of the largest BST is "<< largestBST(root);  
  
    return 0;  
}  
  
// This code is contributed by rathbhupendra 