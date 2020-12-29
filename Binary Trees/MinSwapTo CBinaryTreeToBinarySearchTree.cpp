//Traverse in Inorder and then use the same method as min swap required to sort an array
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
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
typedef vector<int>		vi;
const int mod = 1000000007;
const int N = 3e5, M = N;


// Inorder Traversal of Binary Tree 
void inorder(int a[], std::vector<int> &v,  
                        int n, int index) 
{ 
  if(index>=n)
    return;

      inorder(a,v,n,index*2+1);
      v.push_back(a[index]);
      inorder(a,v,n,index*2+2);
    
} 
  
// Function to find minimum swaps to sort an array 
int minSwaps(std::vector<int> &v) 
{



int n=v.size();
vector<pair<int,int>> tol(n);
vector<bool> bol(n,false);

for(int i=0;i<n;i++)
  tol[i] = {v[i],i};

sort(tol.begin(),tol.end());


// for(int i=0;i<n;i++)
// deb(v[i]);
// for(int i=0;i<n;i++)
//   deb2(tol[i].F,tol[i].S);

int Res = 0; 
for(int i=0;i<n;i++)
{
  if(tol[i].second==i or bol[i])
  continue;

  int count = 0;
  int j=i;
  while(!bol[j])
  {
    bol[j]=true;
    j = tol[j].second;
    count++;
  }
  Res+=count-1;
}

return Res;

}
  
// Driver code 
int main() 
{ 
    int a[] = { 5, 6, 7, 8, 9, 10, 11 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    std::vector<int> v; 
    inorder(a, v, n, 0); 
    cout << minSwaps(v) << endl; 
} 