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


vector<vector<char>> Matrix ={
            {'D','D','D','G','D','D'},
            {'B','B','D','E','B','S'},
            {'B','S','K','E','B','K'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','G'}
           };

 string str= "GEEKS";
 vector <int> X ={ -1, -1, -1, 0, 0, 1, 1, 1 }; 
 vector <int> Y= { -1, 0, 1, -1, 1, -1, 0, 1 };

 bool search_matrix(vector<vector<char>> &Matrix,int row,int col,string &str)
 {

   //deb2(row,col);

   int R = Matrix.size();
   int C = Matrix[0].size();
   if(Matrix[row][col]!=str[0])
   return false;
   int len=str.size();
   for(int i=0;i<8;i++)
   {
     int cc = col + X[i];
     int cr = row + Y[i];
     int j;
     for(j=1;j<len;j++)
     {
       if(cc<0 or cr<0 or cc>=C or cr>=R)
       break;
       if(Matrix[cr][cc]!=str[j])
       break;

      // deb(Matrix[cc][cr]);

       cc+=X[i];
       cr+=Y[i];
     }
     if (j==len)
     return true;
   }
   return false;
   

 }

bool search(vector<vector<char>> &Matrix,string &str)
{
for(int i=0;i<Matrix.size();i++)
{
  for(int j=0;j<Matrix[0].size();j++)
  {
    if(search_matrix(Matrix,i,j,str))
    return true;
  }
}
return false;
}

int main() {
    FIN
    int s;
    int i,j;
    s=1;
    while(s--)
    {
        cout<<(search(Matrix,str)?"YES":"NO");
        cout<<endl;
    }

    return 0;
}