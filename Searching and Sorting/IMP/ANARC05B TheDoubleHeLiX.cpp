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



int theDoubleHeLiX(vector<int> &A,vector<int> &B)
{

int i=0,j=0;

int n1= A.size();
int n2= B.size();

int Asum = 0;
int Bsum= 0;
int Msum=0;

while(i<n1 and j<n2)
{
  while(i < n1 and A[i]<B[j])
  {
    Asum+=A[i];
    i++;
  }
  while(j<n2 and B[j]<A[i])
  {
    Bsum+=B[j];
    j++;
  }
  if(i!=n1 and j!=n2 and A[i]==B[j])
  {
                      //  deb2(i,j);
                      //  deb2(A[i],B[j]);
    Msum=max(Asum,Bsum);
    Msum+=A[i];
    Asum=Msum;
    Bsum=Msum;
    
                    //    deb(Msum);
    i++;
    j++;
  }
}

if(Asum-Msum!=0)
{
int Rsum=0;
while(j!=n2)
Rsum+=B[j++];
Msum += max(Rsum,Asum-Msum);
}

if(Bsum-Msum!=0)
{
int Rsum=0;
while(i!=n1)
Rsum+=A[i++];
Msum += max(Rsum,Bsum-Msum);
}

return Msum;
}


int main() {
    FIN
        int n;
        cin>>n;
        int i;
        while(n!=0)
        {
        vi ar(n);
        fo(i,n)
        cin>>ar[i];
        int n2;cin>>n2;

         vi ar2(n2);
        fo(i,n2)
        cin>>ar2[i];
        cout<<theDoubleHeLiX(ar,ar2);
        cout<<endl;
        cin>>n;
        }

    return 0;
}


