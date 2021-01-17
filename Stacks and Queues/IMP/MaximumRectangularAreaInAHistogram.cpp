
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

//Vector

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

void NearestSmallestLleft(vector<int> &ar,int n,vector<int> &NSL)
{
  stack<pair<int,int>> s;
  NSL[0]=-1;
  s.push({ar[0],0});
  for(int i=1;i<n;i++)
  {
    while(!s.empty() and ar[i]<s.top().first)
    {
      s.pop();
    }
    if(!s.empty() and ar[i]>s.top().first)
    {
      NSL[i]=s.top().second;
      s.push({ar[i],i});
    }
    if(s.empty())
    {
      NSL[i]=-1;
      s.push({ar[i],i});
      continue;
    }
  }
 // debvec(NSL);
}

void NearestSmallestLRight(vector<int> &ar,int n,vector<int> &NSR)
{
  stack<pair<int,int>> s;
  NSR[n-1]=n;
  s.push({ar[n-1],n-1});
  for(int i=n-2;i>=0;i--)
  {
    while(!s.empty() and ar[i]<s.top().first)
    {
      s.pop();
    }
    if(!s.empty() and ar[i]>s.top().first)
    {
      NSR[i]=s.top().second;
      s.push({ar[i],i});
    }
    if(s.empty())
    {
      NSR[i]=n;
      s.push({ar[i],i});
      continue;
    }
  }
 // debvec(NSR);
}

int maxAreainAHist(vector<int> &ar,int n)
{
 // debvec(ar);
  vector<int> NSL(n);
  NearestSmallestLleft(ar,n,NSL);

  vector<int> NSR(n);
  NearestSmallestLRight(ar,n,NSR);

  int res=INT_MIN;
  for(int i=0;i<n;i++)
  {
   // deb(res);
    res = max(res, ar[i]*(NSR[i]-NSL[i]-1) );
  }
  return res;
}

int main() {
    FIN
    int s;
    int i,j;
    
    cin>>s;
    while(s--)
    {
        int n;
        cin>>n;
        vi ar(n);
        fo(i,n)
        cin>>ar[i];
        cout<<maxAreainAHist(ar,n)<<endl;
    }

    return 0;
}