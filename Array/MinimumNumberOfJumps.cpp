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

int main() {
    FIN
    int n,i,j;
    cin>>n;
    while(n--)
    {
      int s;
      cin>>s;
      
      vi ar(s);
      fo(i,s)
      cin>>ar[i];

      vi T(s,INT_MAX);
      if(ar[0]>0)
      T[0]=0;

      for(j=1;j<s;j++)
      {
        for(i=0;i<j;i++)
        {
          if(ar[i]>=j-i)
          T[j]=min(T[j],T[i]+1);
        }
        // deb(j);
        // fo(i,s)
        // cout<<T[i]<<" ";
        // cout<<endl;
      }
      cout<<T[s-1]<<endl;
    }
    
    return 0;
}
