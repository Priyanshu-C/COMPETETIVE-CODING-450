
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
// MIN_HEAP
// I think we can do better than using a min heap to solve this quesiton, will try that later. For now this is the best approach i can think of.

int KthSmallestElement(vector<vector <int>> &ar,int &R,int &C,int k)
{
  int init = 0;
  priority_queue<int, vector<int>, less<int>> pq;
  for(int i=0;i<C;i++)
  pq.push(ar[0][i]);

  for(int i=1;i<R;i++)
  {
    for(int j=0;j<C;j++)
    {
      pq.push(ar[i][j]);
      while(pq.size()>k)
      pq.pop();
    }
  }
  return pq.top();
  
}

int main() {
    FIN
    int s;
    int i,j;
    
    cin>>s;
    while(s--)
    {
        int k;
        cin>>k;
        int r,c;
        cin>>r>>c;
        vector<vector<int>> arr(r,vector<int>(c));
        fo(i,r)
        fo(j,c)
        cin>>arr[i][j];
        cout<<KthSmallestElement(arr,r,c,k);

    }

    return 0;
}