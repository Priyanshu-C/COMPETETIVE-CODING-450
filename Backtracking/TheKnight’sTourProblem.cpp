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

vector<int> X = {1,2,-1,-2,1,2,-1,-2};
vector<int> Y = {2,1,2,1,-2,-1,-2,-1};

//2-D Matrix

void debmat(vector<vector<int>> &ar)
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

bool knightTourUtil(int x,int y,vector<vector<int>> &MATRIX,int count,int len)
{
debmat(MATRIX);
if(count == len*len)
return true;

if(x<0 or y<0 or x>=len or y>=len or MATRIX[x][y]==1)
return false;

MATRIX[x][y]=1;
for(int i=0;i<8;i++)
{
  if(knightTourUtil(x+X[i],y+Y[i], MATRIX,count+1,len))
  return true;
}
MATRIX[x][y]=0;
return false;
}

bool knightTour(int s)
{
  vector<vector<int>> MATRIX(s,vector<int>(s,0)); 
  return knightTourUtil(0,0,MATRIX,0,s);
}

int main() {
    FIN
    int s;
    int i,j;
    
    cin>>s;
    cout<<knightTour(s);

    return 0;
}