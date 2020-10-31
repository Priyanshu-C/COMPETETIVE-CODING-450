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


int Merge(vector<int> &ar,vector<int> &temp,int low,int mid,int right)
{

int i,k,j;
int invcount=0;

i=low;
k=low;
j=mid;

while ( (i<= mid-1) and (j<=right))
{
    if(ar[i]<=ar[j])
    {
        temp[k++]=ar[i++];
    }
    else
    {
        temp[k++]=ar[j++];
        invcount = invcount + (mid - i);
    }
}
while (i <= mid - 1)
    temp[k++] = ar[i++];

while (j <= right)
    temp[k++] = ar[j++];
    
for (i = low; i <= right; i++)
    ar[i] = temp[i];
return invcount;

}

int MergeSort(vector<int> &ar,vector<int> &temp,int low,int high)
            {
                
                deb2(low,high);
                cout<<endl;
                for(int i=0;i<ar.size();i++)
                    cout<<temp[i]<<" ";
                cout<<endl;

                int invcount = 0;
                if(low<high)
                {
                    int mid=(low+high)/2;
                    deb(mid);
                   invcount+= MergeSort(ar,temp,low,mid);
                   invcount+= MergeSort(ar,temp,mid+1,high);
                   invcount+= Merge(ar,temp,low,mid+1,high);
                }
            return invcount;
            }
int main() {

    FIN
    int n,i,j;
    cin>>n;
    vector <int> ar(n);

    for(int i=0;i<n;i++)
    cin>>ar[i];

    vector<int> temp(n);
    cout<<MergeSort(ar,temp,0,n-1);

    for(int i=0;i<n;i++)
    cout<<ar[i]<<" ";

    return 0;
}
