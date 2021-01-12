
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================
  
//STACK

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

int prec(char x)
{
  switch(x)
  {
    case '^':return 3; 
    case '*':return 2; 
    case '/':return 2; 
    case '+':return 1; 
    case '-':return 1; 
  }
 return -1;
}

string infixToPostfix(string &str)
{
  stack<char> s;
  string res="";
  for(char i:str)
  {
    //deb(res);
    //debstack(s);
    if(i=='{' or i=='[' or i=='(')
    {
      s.push(i);
      continue;
    }

    if(i=='}' or i==']' or i==')')
    {
      while((s.top()!='{' and s.top()!='{' and s.top()!='('))
      {
       // deb(s.top());
        res+=s.top();
        s.pop();
      }
      s.pop();
      continue;
    }
    
    if(prec(i)==-1)
    {
      //deb(i);
      res+=i;
    }
    else
    {
      
      while(!s.empty() and prec(s.top())!=-1 and prec(s.top())>=prec(i))
      {
        res+=s.top();
        s.pop();
      }
      s.push(i);
    }
  }
  while(!s.empty())
  {
    res+=s.top();
    s.pop();
  }
  return res;
}

int main() {
    FIN
    
    string str="a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(str);

    return 0;
}