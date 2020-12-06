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

//Right Solution 

// int t, n, c;
// int a[me];
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     cin >> t;
//     while(t --){
//         cin >> n >> c;
//         for(int i = 0; i < n; i ++)
//             cin >> a[i];
        
//         sort(a, a + n);
//         int low = 0, high = a[n-1], mid, best = 0;
//         while(low <= high){
//             mid = (low + high + 1) / 2;
//             int cnt = 1, left = 0;
//             for(int i = 1; i < n && cnt < c; i ++){
//                 if(a[i] - a[left] >= mid)
//                     left = i, cnt ++;
//             }
//             if(cnt >= c){
//                 best = mid;
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
//         cout << best << endl;
//     }
    
//     return 0;
// }

pair<int,int> testRun(vector<int> &Barn,int GAP,int C)
{
  //deb(GAP);
  int count=1;
  int j=0;

  int lastIndex=0;
  int minG=INT_MIN;
  int reqSum=0;
  int sum=0;
  while(j<Barn.size())
  { 
  //deb2(sum,count);
   sum+=Barn[j];
  if(sum>=reqSum and count <C)
  {
    minG = max(minG,j-lastIndex);
    lastIndex = j;
   // deb(Barn[j]);
    reqSum+=GAP;
    count++;
  }
  j++;
  }
 // cout<<"FINAL"<<count<<endl;
  return {count==C,minG};
}


int AGGRCOW(vector<int> &Barn,int C)
{
  int minG=INT_MIN;
  sort(Barn.begin(),Barn.end());
  int n=Barn.size();

  int low = Barn[0];
  int high = Barn[n-1];

  int lastCheckGap = 0;
  while(low<=high)
  {
  int mid = (low+high)/2;

 //deb(mid);
 // deb2(low,high);
  pair<int,int> X = testRun(Barn,mid,C);
  if(X.first)
  {
    if(minG<X.second)
    minG=X.second; 
  low=mid+1;
  }
  else
  high=mid-1;

  //deb(minG);
  }

return minG;
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
        int k;cin>>k;
        vi ar(n);
        fo(i,n)
        cin>>ar[i];
        cout<<AGGRCOW(ar,k);
        cout<<endl;
    }
    return 0;
}


