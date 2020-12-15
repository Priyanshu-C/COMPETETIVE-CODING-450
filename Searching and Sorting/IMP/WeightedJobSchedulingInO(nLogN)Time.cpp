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

struct Jobs {
int S,F,P;
};

void debJobs(vector<Jobs> &ar)
{
  cout<<endl<<"////////////////////"<<endl;
 for(Jobs i:ar)
 cout<<i.S<<"  "<<i.F<<"  "<<i.P<<endl;
 cout<<endl<<"////////////////////"<<endl;
}

bool COMP(Jobs A,Jobs B)
{
  return A.F < B.F;
}

bool possible(vector<Jobs> &ar,int &j,int &i)
{
  if(ar[i].S<ar[j].S and ar[i].F<ar[j].F)
  return true;
  return false;
}

int weightedJobSheduled(vector<Jobs> &ar)
{
  int n=ar.size();
  sort(ar.begin(),ar.end(),COMP);
 // debJobs(ar);

  vector<int> DP(n,0);
  DP[0]=ar[0].P;
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(possible(ar,i,j))
      DP[i]=max(DP[i],DP[j]+ar[i].P);
    }

    // cout<<endl;
    // for(int i:DP)
    // cout<<i<<" ";
    // cout<<endl;


  }

    //  cout<<endl<<"END";
    // for(int i:DP)
    // cout<<i<<" ";
    // cout<<endl;


    return DP[n-1];

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
       vector<Jobs> ar(n);
       fo(i,n)
       {
         int k,l,m;
         cin>>k>>l>>m;
         ar[i] = {k,l,m};
       }

      cout<<weightedJobSheduled(ar);
    }
    return 0;
}


