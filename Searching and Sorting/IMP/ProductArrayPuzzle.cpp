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
//METHOD 1
void productArrayPuzzle(vector<int> &ar)
{
int C0=0;
int prod=1;
int n=ar.size();
for(int i:ar)
{
  if(i!=0)
  prod=prod*i;
  else
  C0++;
}
if(C0>1)
{
  for(int i=0;i<n;i++)
  {
    ar[i]=0;
  }
}
else if(C0==1)
{
  for(int i=0;i<n;i++)
  {
    if(ar[i]==0)
    ar[i]=prod;
    else
    ar[i]=0;
  }
}
else
{
  for(int i=0;i<n;i++)
  {
    ar[i]=prod/ar[i];
  }
}
}

// METHOD 2
//When to do it without division simply,
// x = a * b * c * d
// log(x) = log(a * b * c * d)
// log(x) = log(a) + log(b) + log(c) + log(d)
// x = antilog(log(a) + log(b) + log(c) + log(d))


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
        productArrayPuzzle(ar);
        for(int i:ar)
        cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
