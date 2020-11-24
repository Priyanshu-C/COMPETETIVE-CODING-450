
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

// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000
// The trick is to go from back to front and keep compapring to add and substract 

int romanToInteger(string str)
{
map<char,int> mp;
mp['I']=1;
mp['V']=5;
mp['X']=10;
mp['L']=50;
mp['C']=100;
mp['D']=500;
mp['M']=1000;
int RES=mp[str[str.size()-1]];
int n=str.size();
for(int i=n-2;i>=0;i--)
{
  if(mp[str[i]]>=mp[str[i+1]])
  RES+=mp[str[i]];
  else
  RES-=mp[str[i]];
}
return RES;
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
        cout<<romanToInteger(x);
        cout<<endl;
    }

    return 0;
}