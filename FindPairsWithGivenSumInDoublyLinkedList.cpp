// C++ program to find a pair with given sum x. 
#include<bits/stdc++.h> 
using namespace std; 
 
// structure of node of doubly linked list 
struct Node 
{ 
    int data; 
    struct Node *next, *prev; 
}; 
void pairSum(struct Node *head, int x) 
{
  Node *first = head;
  Node *second = head;
  while(second->next!=NULL)
  second=second->next;

  while(!first and !second and first!=second)
  {
    if(first->data+second->data == x)
    {
      cout<<first->data<<" "<<second->data;
      first = first->next;
      second = second->prev;
    }
    else
    {
      if(first->data+second->data<x)
      {
        first=first->next;
      }
      else
      second=second->prev;
    }
  }



}

// A utility function to insert a new node at the 
// beginning of doubly linked list 
void insert(struct Node **head, int data) 
{ 
    struct Node *temp = new Node; 
    temp->data = data; 
    temp->next = temp->prev = NULL; 
    if (!(*head)) 
        (*head) = temp; 
    else
    { 
        temp->next = *head; 
        (*head)->prev = temp; 
        (*head) = temp; 
    } 
} 
 
// Driver program 
int main() 
{ 
    struct Node *head = NULL; 
    insert(&head, 9); 
    insert(&head, 8); 
    insert(&head, 6); 
    insert(&head, 5); 
    insert(&head, 4); 
    insert(&head, 2); 
    insert(&head, 1); 
    int x = 7; 
 
    pairSum(head, x); 
 
    return 0; 
} 