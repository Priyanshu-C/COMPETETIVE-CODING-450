
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

void debmat(vector<vector<int>> &ar)
{
  cout<<endl<<"////////////////////////////"<<endl;
  int R=ar.size();
  int C=ar[0].size();
  int i,j;
  fo(i,R)
  {
    fo(j,C)
    cout<<ar[i][j]<<"  ";
    cout<<endl;
  }
  cout<<"////////////////////////////"<<endl;

}

int minDistance(string S1,string S2) {

  int n=S1.size();
  int m=S2.size();
  vector<vector<int>> DP(n+1,vector<int>(m+1,0));
  for(int i=0;i<=n;i++)
  DP[i][0]=i;
  for(int j=0;j<=m;j++)
  DP[0][j]=j;
  debmat(DP);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(S1[i-1]==S2[j-1])
      DP[i][j]=DP[i-1][j-1];
      else
      DP[i][j]=min(DP[i-1][j],min(DP[i][j-1],DP[i-1][j-1]))+1;
    }
    debmat(DP);
  }
  return DP[n][m];
}
    

int main() {
    FIN
    int s;
    int i,j;
    cin>>s;
    while(s--)
    {
        string n,k;
        cin>>n>>k;

        cout<<minDistance(n,k)<<" ";
      
        
    }

    return 0;
}