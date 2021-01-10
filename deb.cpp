//STACK

#define fo(i,n) for(int i=0;i<n;i++)

void debstack(stack<char> s)
{
  cout<<endl<<"...........";
  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl<<"...........";
}

//2-D Matrix

#define fo(i,n) for(int i=0;i<n;i++)
void debmat(vector<vector<int>> &ar)
{
  int R=ar.size();
  int C=ar[0].size();
  int i,j;
  cout<<endl<<"////////////"<<endl;
  fo(i,R)
  {
    fo(j,C)
    cout<<ar[i][j]<<"  ";
    cout<<endl;
  }
  cout<<endl<<"////////////"<<endl;
}

//Vector

#define fo(i,n) for(int i=0;i<n;i++)
void debvec(vector<int> &ar)
{
  int R=ar.size();
  int i;
  cout<<endl<<"////////////"<<endl;
  fo(i,R)
  {
    cout<<ar[i]<<"  ";
  }
  cout<<endl<<"////////////"<<endl;
}