
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

// Better way to do it will be create two arrays one to staore the address of nodes in DLL and bool array for char exists already or not simple.
// https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/ 

string findFirstNonRepeating(string &s)
{

vector<bool> ar(256,false);
list<char> li;
string res="";
for(char i:s)
{
  if(!ar[i])
  {
    li.push_back(i);
    ar[i]=true;
  }
  else 
    {
      li.remove(i);
    }

  if(li.size()==0)
  res+='#';
  else
  res+=li.front();
}
return res;

}

int main() {
    FIN
    string s;
    cin>>s;

    cout<<findFirstNonRepeating(s);

    return 0;
}