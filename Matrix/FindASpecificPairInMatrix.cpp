
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

// Simply go from bottom-right to top-left to great and get the max element in the bottom right matrix of the selected element 
// keep checking for the max pair 

void debmat(vector<vector<int>> &ar)
{
  int R=ar.size();
  int C=ar[0].size();
  int i,j;
  fo(i,R)
  {
    fo(j,C)
    cout<<ar[i][j]<<"  ";
    cout<<endl;
  }
  cout<<"////////////"<<endl;

}

int findSpecificPair(vector<vector<int>> &ar,int &R,int &C)
{
  int maxPair = INT_MIN;
  for(int i=1;i<C;i++)
  {
    ar[R-1][C-i-1]=max(ar[R-1][C-i],ar[R-1][C-i-1]);
  }

 // debmat(ar);
  
  for(int i=1;i<R;i++)
  {
    ar[R-1-i][C-1]=max(ar[R-i][C-1],ar[R-1-i][C-1]);
  }

  // debmat(ar);

   for(int i=R-2;i>=0;i--)
   {
     for(int j=C-2;j>=0;j--)
     {
       maxPair = max(maxPair,ar[i+1][j+1]-ar[i][j]);
       ar[i][j]=max(ar[i+1][j],ar[i][j+1]);
        // debmat(ar);
        // deb(maxPair);
     }
     
   }

return maxPair;

}

int main() {
    FIN
    int s=1;
    int i,j;
    
    // cin>>s;
    while(s--)
    {
        int r=5,c=5;

        // cin>>r>>c;
        vector<vector<int>> arr={{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
        // fo(i,r)
        // fo(j,c)
        // cin>>arr[i][j];
        cout<<findSpecificPair(arr,r,c);
    }

    return 0;
}