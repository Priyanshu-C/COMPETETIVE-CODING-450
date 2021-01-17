#include <bits/stdc++.h>
using namespace std;

#define d(x) cout<<#x<<" "<<x<<endl;

class DLL{
  public:
int val;
DLL *next;
DLL *prev;
  DLL()
  {
    val=-1;
    next=NULL;
    prev=NULL;
  }
  DLL(int val)
  {
    val=val;
    next=NULL;
    prev=NULL;
  }
};

class Stack
{
  private:
  DLL *head = NULL;
  DLL *mid = NULL;
  int count=0;
  public:
  void push(int val)
  {
    
    if(head==NULL)
    {
      head=new DLL();
      head->val=val;
    }
    else
    {
      DLL *temp = new DLL();
      temp->val=val;
      temp->next=head;
      head->prev=temp;
      head=temp;
    }
    count++;
    if(mid==NULL)
    mid=head;
    else
    {
    if(count%2==1)
    mid=mid->prev;
    }
    d(head->val);
    d(mid->val);

  }
  void pop()
  {
    if(head==NULL)
    return;
    if(head->next==NULL)
    {
      head=NULL;
      mid=NULL;
      count=0;
      return;
    }
    head=head->next;
    count--;
    if(count%2==1)
    mid=mid->next;
    d(head->val);
    d(mid->val);
  }
  int findMiddle()
  {
   if(head==NULL)
   return INT_MAX;
   return mid->val;
  }
  void deleteMiddle()
  {
    if(!mid->next and !mid->prev)
    {
      mid=NULL;
      head=NULL;
      count=0;
      return;
    }
    if(!mid->next)
    {
      mid=head;
      head->next=NULL;
      count--;
      return;
    }
    mid->next->prev=mid->prev;
    count--;
    return;
  }
};

int main()
{
Stack s;
s.push(1);
s.push(2);
s.deleteMiddle();
s.push(3);
s.push(4);
s.pop();s.pop();
cout<<s.findMiddle();
s.deleteMiddle();
}