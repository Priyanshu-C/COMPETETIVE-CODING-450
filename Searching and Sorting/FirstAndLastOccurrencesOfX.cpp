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

//left side is true and right is false

int binarySearchR(int low,int high,vector<int> &ar,int &x)
{
  if(low<=high)
  {
  int mid=(low+high)/2;
  if(mid == ar.size()-1 or (x>ar[mid-1] and x==ar[mid]))
  return mid;
  else if(x > ar[mid])
  return binarySearchR(mid+1,high,ar,x);
  else
  return binarySearchR(low,mid-1,ar,x);
  }
  return -1;
}

int binarySearchL(int low,int high,vector<int> &ar,int &x)
{
  if(low<=high)
  {
  int mid=(low+high)/2;
  if(mid == 0 or (x<ar[mid+1] and x==ar[mid]))
  return mid;
  else if(x<ar[mid])
  return binarySearchL(low,mid-1,ar,x);
  else
  return binarySearchL(mid+1,high,ar,x);
  }
  return -1;
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
        vi ar(n);
        fo(i,n)
        cin>>ar[i];
        int x;
        cin>>x;
        int L = binarySearchR(0,ar.size(),ar,x);
        int R = binarySearchL(0,ar.size(),ar,x);
        //deb2(L,R);
        if(L==-1 or R==-1)
        cout<<"BLAH";
        else
        cout<<L<<" "<<R;
        cout<<endl;
    }

    return 0;
}
