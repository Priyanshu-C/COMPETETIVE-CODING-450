// f(n) = ways n people can remain single 
//        or pair up.

// For n-th person there are two choices:
// 1) n-th person remains single, we recur 
//    for f(n - 1)
// 2) n-th person pairs up with any of the 
//    remaining n - 1 persons. We get (n - 1) * f(n - 2)

// Therefore we can recursively write f(n) as:
// f(n) = f(n - 1) + (n - 1) * f(n - 2)

#include <bits/stdc++.h> 
using namespace std; 
  
// Returns count of ways n people 
// can remain single or paired up. 
int countFriendsPairings(int n) 
{ 
    int dp[n + 1]; 
  
    // Filling dp[] in bottom-up manner using 
    // recursive formula explained above. 
    for (int i = 0; i <= n; i++) { 
        if (i <= 2) 
            dp[i] = i; 
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2]; 
    } 
  
    return dp[n]; 
} 
  
// Driver code 
int main() 
{ 
    int n = 4; 
    cout << countFriendsPairings(n) << endl; 
    return 0; 
}