// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

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

vi g[N];
int a[N];

int main() {
    FIN
    int n,i,j;
    cin>>n;
    while(n--)
    {
        int s;cin>>s;
        vi ar(s);
        
        fo(i,s)
        cin>>ar[i];

        if(n==1)
        cout<<ar[0]<<" "<<ar[0];

        int max,min;
        if(s%2==1)
        {
            min=ar[0];
            max=ar[0];
            i=1;
        }
        else
        {
            if(ar[0]>ar[1])
            {
                min=ar[1];
                max=ar[0];
            }
            else
            {
                min=ar[0];
                max=ar[1];
            }
            i=2;
        }
        for(;i<s-1;i=i+2)
        {
            if(ar[i]>ar[i+1])
            {
                if(max<ar[i])
                max=ar[i];
                if(min>ar[i+1])
                min=ar[i+1];
            }
            else
            {
                if(max<ar[i+1])
                max=ar[i+1];
                if(min>ar[i])
                min=ar[i];
            }
            
        }
        deb(min);
        deb(max);   
    }

    return 0;
}