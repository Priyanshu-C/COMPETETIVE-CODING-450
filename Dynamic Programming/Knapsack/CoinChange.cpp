#define d(x) cout<<#x<<" "<<x<<endl;
class Solution
{
  public:
     
    long long int countUtil( int S[], int m, int n,int i,vector<vector<long long int>> &DP)
    {
        if(n==0)
        return 1;

        if(i>=m or n<0)
        return 0;
        if(DP[i][n]!=-1)
        return DP[i][n];
        
        if(S[i]<=n)
        DP[i][n]= countUtil(S,m,n-S[i],i,DP) + countUtil(S,m,n,i+1,DP);
        else
        DP[i][n]= countUtil(S,m,n,i+1,DP);
        return DP[i][n];
    } 
    long long int count( int S[], int m, int n)
    {
        vector<vector<long long int>> DP(1001,vector<long long int>(1001,-1));
        return countUtil(S,m,n,0,DP);
    }
};