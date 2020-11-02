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

int tripleSumInArray(vector<int> &ar,int n,int k)
{

unordered_map<int,int> mp;

for(int i:ar)
mp[i]++;

int flag = 0;

for(int i=0;i<n;i++)
{
  for(int j=i+1;j<n;j++)
  {
    int sumreq = k - (ar[i]+ar[j]);
    if(mp.find(sumreq)!=mp.end())
    {
      if((sumreq == ar[i] or sumreq == ar[j]) and mp[sumreq] < 2 );
      else
      flag=1;
    }
  }
}
return flag;

}

int main() {
    FIN
    int s;
    int i,j;
    
    cin>>s;
    while(s--)
    {
        int n,k;
        cin>>n;
        cin>>k;
        vi ar(n);
        fo(i,n)
        cin>>ar[i];
        cout<<tripleSumInArray(ar,n,k)<<endl;
    }

    return 0;
}