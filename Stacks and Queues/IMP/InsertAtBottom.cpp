
#include <bits/stdc++.h>
using namespace std;

//STACK

#define fo(i,n) for(int i=0;i<n;i++)

void debstack(stack<int> s)
{
  cout<<endl<<"...........";
  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl<<"...........";
}

void insertAtBottom(stack<int> &s,int x)
{
    if(s.size()==0)
    {
      s.push(x);
      return;
    }
    else
    {
      int a = s.top();
      s.pop();
      insertAtBottom(s,x);
      s.push(a);
    }
}
 
// Driver Code
int main()
{
    stack<int> s;
 
   
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
 
   
    insertAtBottom(s,9);
    debstack(s);
 
    return 0;
}