
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

void sortInsert(stack<int> &s,int x)
{
    if(s.empty() or s.top()<x)
    {
      s.push(x);
    }
    else
    {
      int a = s.top();
      s.pop();
      sortInsert(s,x);
      s.push(a);
    }
}
 
 void sort(stack<int> &s)
 {
  if(s.size()>0)
  {
    int a = s.top();
    s.pop();
    sort(s);
    sortInsert(s,a);
  }
 }

// Driver Code
int main()
{
    stack<int> s;
 
   
    s.push(1);
    s.push(8);
    s.push(43);
    s.push(4);
 
   
    sort(s);
    debstack(s);
 
    return 0;
}