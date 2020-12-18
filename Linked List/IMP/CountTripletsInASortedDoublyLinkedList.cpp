// C++ implementation to count triplets in a sorted doubly linked list 
// whose sum is equal to a given value 'x' 
#include <bits/stdc++.h> 
  
using namespace std; 
  
// structure of node of doubly linked list 
struct Node { 
    int data; 
    struct Node* next, *prev; 
}; 
  
// function to count pairs whose sum equal to given 'value' 
int countPairs(struct Node* first, struct Node* second, int value) 
{ 
  int count = 0;
  while(first and second and first->next!=second)
  {
    if(first->data+second->data==value)
    {
      count++;
      first=first->next;
      second=second->prev;  
    }
    else if(first->data+second->data<value)
    first=first->next;
    else
    second=second->prev; 
  }
  return count;
} 
  
// function to count triplets in a sorted doubly linked list 
// whose sum is equal to a given value 'x' 
int countTriplets(struct Node* head, int x) 
{ 
  if(head==NULL)
  return 0;
int count=0;
Node *pointer = head;
Node *first = head;
Node *last = head;
while(last->next!=NULL)
  last=last->next;

for(pointer=head;pointer->next!=NULL;pointer=pointer->next)
{
count+=countPairs(pointer->next,last,x-pointer->data);
}
return count;
} 
  
// A utility function to insert a new node at the 
// beginning of doubly linked list 
void insert(struct Node** head, int data) 
{ 
    // allocate node 
    struct Node* temp = new Node(); 
  
    // put in the data 
    temp->data = data; 
    temp->next = temp->prev = NULL; 
  
    if ((*head) == NULL) 
        (*head) = temp; 
    else { 
        temp->next = *head; 
        (*head)->prev = temp; 
        (*head) = temp; 
    } 
} 
  
// Driver program to test above 
int main() 
{ 
    // start with an empty doubly linked list 
    struct Node* head = NULL; 
  
    // insert values in sorted order 
    insert(&head, 9); 
    insert(&head, 8); 
    insert(&head, 6); 
    insert(&head, 5); 
    insert(&head, 4); 
    insert(&head, 2); 
    insert(&head, 1); 
  
    int x = 17; 
  
    cout << "Count = "
         << countTriplets(head, x); 
    return 0; 
} 