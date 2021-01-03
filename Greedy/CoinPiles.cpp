
#include <bits/stdc++.h> 
using namespace std; 
  

int minimumCoins(int a[], int n, int k) 
{ 
    
    int cnt = 0; 
  
    int minVal = *min_element(a, a + n); 
  

    for (int i = 0; i < n; i++) { 
        int diff = a[i] - minVal; 

        if (diff > k) { 
            cnt += (diff - k); 
        } 
    } 

    return cnt; 
} 
  
int main() 
{ 
    int a[] = { 1, 5, 1, 2, 5, 1 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int k = 3; 
  
    cout << minimumCoins(a, n, k); 
  
    return 0; 
}