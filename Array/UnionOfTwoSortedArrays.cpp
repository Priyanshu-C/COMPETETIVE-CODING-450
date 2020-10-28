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
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

void uni(vi &ar1,int s1,vi &ar2,int s2)
{
  int i=0,j=0;
  while(i<s1 and j<s2)
  {
    while(ar1[i]<=ar2[j] and i<s1)
    {
      cout<<ar1[i]<<" ";
      i++;
    }
    while(ar1[i]>=ar2[j] and j<s2)
    {
      cout<<ar2[j]<<" ";
      j++;
    }
  }
  while(i<s1)
  {
    cout<<ar1[i]<<" ";
    i++;
  }
  while(j<s2)
  {
    cout<<ar2[j]<<" ";
    j++;
  }
}

int main() {
    FIN
    int n,i,j;
    cin>>n;
    while(n--)
    {
    int s1,s2;
    cin>>s1>>s2;
    
    deb2(s1,s2);

    vi ar1(s1);
    fo(i,s1)
    cin>>ar1[i];

    vi ar2(s2);
    fo(i,s2)
    cin>>ar2[i];

    // //Method 1
    // sortall(ar1);
    // sortall(ar2);
    // uni(ar1,s1,ar2,s2);
    // cout<<endl;

    // Method 2 
    vi hash(N,0);
    fo(i,s1)
    hash[ar1[i]]++;
    fo(i,s2)
    hash[ar2[i]]++;

    fo(i,N)
    {
      if(hash[i]<0)
      {
        fo(j,hash[i])
        {
          cout<<i<<" ";
        }
      }
    }

    }
    return 0;
}
