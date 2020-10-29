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

int main() {
    FIN
    int n,i,j;
    int s1,s2;
    cin>>s1>>s2;
    vi ar1(s1);
    vi ar2(s2);

    fo(i,s1)
    cin>>ar1[i];

    fo(i,s2)
    cin>>ar2[i];

    ar1.insert(ar1.end(),all(ar2));

    /// 1st Method will be making third array but that's not allowed
    /// 2nd Method will be talking number from 2nd array and swap and sort 
    /// GAPP METHOD

    n=s1+s2;
    int GAP = ceil(n/2);

    while(GAP!=0)
    {
    for(int i=0;i+GAP<n;i++)
    {
      if(ar1[i+GAP]<ar1[i])
      swap(ar1[i+GAP],ar1[i]);
    }
    GAP/=2;
    } 

    fo(i,s1+s2)
    cout<<ar1[i]<<" ";

    return 0;
}
