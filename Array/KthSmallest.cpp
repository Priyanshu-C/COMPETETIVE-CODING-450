//https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

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
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

//Approach 1 (simple)

// int main() {
//     //FIN
//     int n,i,j;
//     cin>>n;
//     fo(i,n)
//     {
//         int s;
//         cin>>s;
//         vi ar(s);
//         fo(j,s)
//         cin>>ar[j];
//         sortall(ar);
//         int k;
//         cin>>k;
//         cout<<ar[k-1]<<endl;
//     }
//     return 0;
// }

//Approach 2 (Quick Select)

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition(vector<int> &ar,int low,int high)
{
    int pivot = ar[high];
    int i = low - 1;
    for(int j = low; j<= high - 1 ; j++)
    {
        if(ar[j]<pivot)
        {
            i++;
            swap(ar[i],ar[j]);
        }
    }
    swap(ar[i+1],ar[high]);
    return (i+1);
}

int kthSmallest(vector <int> &arr, int l, int r, int k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) { 
        // Partition the array around last element and get 
        // position of pivot element in sorted array 
        int pos = partition(arr, l, r); 
  
        // If position is same as k 
        if (pos - l == k - 1) 
            return arr[pos]; 
        if (pos - l > k - 1) // If position is more, recur for left subarray 
            return kthSmallest(arr, l, pos - 1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1); 
    } 
  
    // If k is more than number of elements in array 
    return INT_MAX; 
} 

int main() {

    FIN
    int n,i,j,k;
    cin>>n;
    vector <int> ar(n);

    for(int i=0;i<n;i++)
    cin>>ar[i];

    cin>>k;

    cout<<kthSmallest(ar,0,ar.size()-1,k)<<endl;

    return 0;
}
