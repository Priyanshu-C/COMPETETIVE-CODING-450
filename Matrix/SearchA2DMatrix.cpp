
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

bool binarySearch(vector<vector<int>>& matrix, int targetrow, int col,int target)
{
        
  int i=0;int j=col-1;
  while(i<=j)
  {
    int mid=(i+j)/2;
    if(matrix[targetrow][mid]==target)
    return true;A
    else if(matrix[targetrow][mid]<target)
    {
      i=mid+1;
    }
    else
    {
      j=mid-1;
    }
  }
return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
//deb2(matrix.size(),matrix[1].size());
int row=matrix.size();
    if(row==0)
        return false;
    cout<<"row"<<row;
int col=matrix[0].size();
    if(col==0)
        return false;
    cout<<"col"<<col;

for(int i=0;i<row;i++)
{
  if(matrix[i][0]<=target and matrix[i][col-1]>=target)
  {
    cout<<i<<col;
    return binarySearch(matrix,i,col,target);
  }
}
return false;
}

int main() {
    FIN
    int s;
    int i,j;
    
    cin>>s;
    while(s--)
    {
        int n1,n2;
        cin>>n1>>n2;
        vector<vector<int>> ar(n1,vector<int>(n2));
        fo(i,n1)
        {
          fo(j,n2)
          {
            cin>>ar[i][j];
          }
        }
                          // cout<<endl;
                          // fo(i,n1)
                          // {
                          //   fo(j,n2)
                          //   cout<<ar[i][j]<<" ";
                          //   cout<<endl;
                          // } 
        cout<<endl; 
        int target;
        cin>>target;
        cout<<searchMatrix(ar,target);  
        cout<<endl;     
    }

    return 0;
}s