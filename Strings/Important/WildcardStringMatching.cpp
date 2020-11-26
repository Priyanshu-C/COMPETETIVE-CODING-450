//https://www.youtube.com/watch?v=3ZDZ-N0EPV0
//Tushar Roy's Wildcard Matching Dynamic Programming

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

void debmat(vector<vector<bool>> &ar)
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
bool wildcardStringMatch(string pattern,string str) {
  int pSize = pattern.size();
  int sSize = str.size();
  vector<vector<bool>> dp(sSize+1,vector<bool> (pSize+1,0));
  

  dp[0][0] = true;
  for(int i=1;i<sSize+1;i++)
  dp[i][0]=false;
  
  for(int i=1;i<pSize+1;i++)
  dp[0][i]=false;
  
  if(pattern[0]=='*')
  dp[0][1]=true;

  for(int i=1;i<sSize+1;i++)
  {
    for(int j=1;j<pSize+1;j++)
    {
      if(str[i-1]==pattern[j-1])
      dp[i][j]=dp[i-1][j-1];
      else
      {
        if(pattern[j-1]=='?')
        {
          dp[i][j]=dp[i-1][j-1]; 
        }
        else if(pattern[j-1]=='*')
        {
          dp[i][j]=dp[i-1][j] or dp[i][j-1];  
        }
        else
        {
          dp[i][j]=false;
        }
      }

    }
  }
  debmat(dp);
  return dp[sSize][pSize];
  
}


int main() {
    FIN
    int s;
    int i,j;
    cin>>s;
    while(s--)
    {
        string x;
        cin>>x;
                string x1;
        cin>>x1;
        cout<<(wildcardStringMatch(x,x1)?"Yes":"No");
        cout<<endl;
    }

    return 0;
}
