
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

// ABCD and ABCD compare by making a 2-D matrix 

int LCSL(string str1,string str2) {
  int n=str1.size();
  int m=str2.size();
  vector<vector<int>> DP(m+1,vector<int>(n+1,0));
  int maxLength=INT_MIN;
  for(int i=1;i<m+1;i++)
  {
    for(int j=1;j<n+1;j++)
    {
      if(str1[i-1]==str2[j-1])
      DP[i][j]=max(DP[i][j-1],DP[i-1][j])+1;
      else
      DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
      maxLength=max(DP[i][j],maxLength);
    }
  }
  return maxLength;
}
    

int main() {
    FIN
    int s;
    int i,j;
    cin>>s;
    while(s--)
    {
        string n,n2;
        cin>>n>>n2;

        cout<<LCSL(n,n2)<<" ";
    }

    return 0;
}