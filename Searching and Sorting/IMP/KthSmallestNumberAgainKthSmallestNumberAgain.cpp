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

//For debugging the Vector of pair
void debVecOfPair(vector<pair<ll,ll>> Ar)
{
  ll i;
  ll n=Ar.size();
   cout<<endl<<"////////////"<<endl;
    fo(i,n)
    cout<<Ar[i].first<<"  "<<Ar[i].second<<endl;
  cout<<endl<<"////////////"<<endl;
}

//Merge Logic
ll merge(vector<pair<ll,ll>>& arr) {
        ll IN = 0;
        ll n=arr.size();
       // cout<<(n);
        if(n==0)
            return 0;
        for(int i=1;i<n;i++)
        {
          //cout<<arr[i].first<<" "<<arr[i].second<<endl;
          if(arr[IN].second>=arr[i].first)
          {
            arr[IN].second=max(arr[i].second,arr[IN].second);
            arr[IN].first=min(arr[i].first,arr[IN].first);
          }
          else
          {
          IN++;
          arr[IN]=arr[i];
          }
        }
    return IN;
}

//Comparator for sorting the vector of pair
bool COMP(pair<ll,ll> X,pair<ll,ll> Y)
{
  return X.first < Y.first;
}

void kthSmallestNumberAgain(ll N,vector<pair<ll,ll>> &Range,ll Q,vector<ll> &KQ)
{
 
  sort(Range.begin(),Range.end(),COMP);
  //debVecOfPair(Range);  
  ll x = merge(Range);
  Range.erase(Range.begin()+x+1,Range.end());
  //debVecOfPair(Range);

  ll sumT=0;
  for(ll i=0;i<Range.size();i++)
  sumT+=Range[i].second-Range[i].first+1;
  for(ll i:KQ)
  {
    ll j=0;
    ll sum=0;
    if(sumT<i)
    {
    cout<<-1<<endl;
    continue;
    }

    while(sum<i and j<Range.size())
    {
      sum+=Range[j].second-Range[j].first+1;
      j++;
    }   
    j--;
    cout<<(Range[j].second-(sum-i))<<endl;
    //ll RES = sum-
   // deb2(i,sum);
  }
}

int main() {
    FIN
    ll s;
    ll i,j;
    cin>>s;
    while(s--)
    {
        ll n;
        cin>>n;
        ll Q;cin>>Q;
        vector<pair<ll,ll>> Range(n);
        ll p,q;
        fo(i,n)
        {
          cin>>p>>q;
          Range[i] = {p,q};
        }
        vl KQ(Q);
        fo(i,Q)
        {
          cin>>KQ[i];
        }
        kthSmallestNumberAgain(n,Range,Q,KQ);
        cout<<endl;
    }
    return 0;
}


