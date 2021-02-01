
#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(int set[], int n, int sum)
{
  // if(sum==0)
  // return true;
  // if(n==0)
  // return false;

  // if(sum<set[n-1])
  // return isSubsetSum(set, n-1, sum);
  // else
  // return isSubsetSum(set, n-1, sum - set[n-1]) or isSubsetSum(set, n-1, sum);

  int number=n;
  vector<vector<bool>> DP(number+1,vector<bool> (sum+1,false));

  for(int i=0;i<number+1;i++)
  {
    for(int j=0;j<sum+1;j++)
    {
      if(i==0)
      DP[i][j]=true;
      else 
      {
        if(j < set[i-1])
        DP[i][j]= DP[i-1][j];
        else
        {
          DP[i][j] = DP[i-1][j] or DP[i-1][j-set[i-1]];
        }
      }
    }
  }
  return DP[number][sum];
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 7;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum))
        printf("Found a subset given sum");
    else
        printf("No subset with given sum");
    return 0;
}
