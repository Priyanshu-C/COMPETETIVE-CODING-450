
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
int choclate(vi LengthArray,vi BreathArray,int L,int B)
{
  sort(LengthArray.begin(),LengthArray.end(),greater<int>());
  sort(BreathArray.begin(),BreathArray.end(),greater<int>());

  int i=0;
  int j=0;
  int Vcost = 1;
  int Hcost = 1;
  int RES=0;
  while(i<L-1 and j<B-1)
  {
    if(LengthArray[i]>BreathArray[j])
    {
      RES+=Hcost*LengthArray[i];
      i++;
      Vcost++;
    }
    else
    {
      RES+=Vcost*BreathArray[j];
      j++;
      Hcost++;
    }
  }

  deb(RES);
  deb2(i,j);

  int total=0;
  while(i<L-1)
  {
    RES+=Hcost*LengthArray[i];
    i++;
  }
  RES+=total;
  total=0;
  while(j<B-1)
  {
    RES+=Vcost*BreathArray[j];
    j++;
  }
  RES+=total;
  return RES;
}
int main() {
    FIN
    int s;
    int i,j;
    
    int Length,Breath;
    cin>>Length>>Breath;

    vi LengthArray(Length-1);
    fo(i,Length-1)
    cin>>LengthArray[i];

    vi BreathArray(Breath-1);
    fo(i,Breath-1)
    cin>>BreathArray[i];

    cout<<choclate(LengthArray,BreathArray,Length,Breath)<<endl;

    return 0;
}