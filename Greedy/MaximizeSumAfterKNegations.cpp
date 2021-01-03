
#include <bits/stdc++.h>
using namespace std;


//Basically you keep changingh the smallest value k times and them sum it
//Think it this was, if we have negative number first it will negate them,them still if we have k left, we simply change the smallest value whether it was negative
int maximumSum(int arr[], int n, int k)
{
   
    for (int i = 1; i <= k; i++) {
        int min = INT_MAX;
        int index = -1;
 
        for (int j = 0; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
 
        //If we a zero then no issues
        if (min == 0)
            break;

        arr[index] = -arr[index];
    }
 
  
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
 

int main()
{
    int arr[] = { -2, 0, 5, -1, 2 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumSum(arr, n, k);
    return 0;
}