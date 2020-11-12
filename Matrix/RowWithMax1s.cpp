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
int binarySearch(vector<vector<int>>& arr, int &targetrow)
    {
      int i=0;
      int j=arr[targetrow].size();
     
    //  int k;
    //  fo(k,j)
    //  cout<<arr[targetrow][k]<<" ";
    //  cout<<endl;

        if(arr[targetrow][0]==1)
        return 0;
      while(i<=j)
      {
        int mid=(i+j)/2;
    
        // deb2(i,j);
        // deb(mid);
    
        if(mid == arr[targetrow].size()-1 or arr[targetrow][mid]==0 and arr[targetrow][mid+1]==1)
        return mid+1;
        else if(arr[targetrow][mid]==1)
        {
          j=mid-1;
        }
        else
        {
          i=mid+1;
        }
      }
    
    return INT_MAX;
    }
    
    
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int minFoundColumn=arr[0].size();
        int minFoundRow=-1;
        int index;
    	for(int i=0;i<n;i++)
        {   
            index = binarySearch(arr,i);
    
           deb(index);
    
            if( index < minFoundColumn )
            {
                minFoundRow = i;
                minFoundColumn = index;
            }
        }
        return minFoundRow;
    }
int main() {
    FIN
    int s;
    int i,j;
    
    cin>>s;
    while(s--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int>> arr(r,vector<int>(c));
        fo(i,r)
        fo(j,c)
        cin>>arr[i][j];
        cout<<rowWithMax1s(arr,r,c);
    }

    return 0;
}
