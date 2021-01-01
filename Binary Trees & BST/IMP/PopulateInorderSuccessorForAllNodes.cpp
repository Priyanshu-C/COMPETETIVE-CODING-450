// C++ program to populate inorder 
// traversal of all nodes 
#include<bits/stdc++.h>
using namespace std;
 
class node 
{ 
    public:
    int data; 
    node *left; 
    node *right; 
    node *next; 
}; 
 
 //Go in inorder while keeping the previous node and then simply assign the value to the next node



/* Set next of p and all descendants of p 
by traversing them in reverse Inorder */
void populateNext(node* p,node *&prev) 
{ 
    if(!p)
    return;
    populateNext(p->left,prev);
    if(prev!=NULL)
    {
      prev->next=p;
    }
    prev=p;

    populateNext(p->right,prev);
    return;
} 
 
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new 
node with the given data and NULL left
and right pointers. */
node* newnode(int data) 
{ 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
    Node->next = NULL; 
 
    return(Node); 
} 
 
// Driver Code
int main() 
{ 
 
    /* Constructed binary tree is 
            10 
            / \ 
        8 12 
        / 
    3 
    */
    node *root = newnode(10); 
    root->left = newnode(8); 
    root->right = newnode(12); 
    root->left->left = newnode(3); 
 
    // Populates nextRight pointer in all nodes 
    node *prev=NULL;
    populateNext(root,prev); 
 
    // Let us see the populated values 
    node *ptr = root->left->left; 
    while(ptr) 
    { 
        // -1 is printed if there is no successor 
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1) 
             << endl; 
        ptr = ptr->next; 
    } 
 
    return 0; 
} 
 
// This code is contributed by rathbhupendra