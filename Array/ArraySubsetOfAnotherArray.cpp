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

bool arraySubsetOfAnother(vector<int> &ar1,int n1,vector<int> &ar2,int n2)
{
map<int,int> mp;
for(int i:ar2)
mp[i]++;

for(int i:ar1)
{
  if(mp.find(i)!=mp.end())
    {
      mp[i]--;
      if(mp[i]==0)
      mp.erase(i);
    }
}
return !mp.empty();

}

int main() {
    FIN
    int s;
    int i,j;
    
    cin>>s;
    while(s--)
    {   vector <string> ans = {"Yes","No"}; 
        int n1,n2;
        cin>>n1>>n2;
        vi ar1(n1);
        vi ar2(n2);
        fo(i,n1)
        cin>>ar1[i];
        fo(i,n2)
        cin>>ar2[i];
        cout<<ans[arraySubsetOfAnother(ar1,n1,ar2,n2)]<<endl;
        
    }

    return 0;
}