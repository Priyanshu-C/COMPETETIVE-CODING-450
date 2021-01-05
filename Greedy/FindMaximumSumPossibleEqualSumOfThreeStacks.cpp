
#include <bits/stdc++.h> 
using namespace std; 
  
int maxSum(int stack1[], int stack2[], int stack3[], int n1, int n2, int n3) 
{ 
  int sum1=0;
  int sum2=0;
  int sum3=0;
  for(int i=0;i<n1;i++)
    sum1+=stack1[i];
    
  for(int i=0;i<n2;i++)
    sum2+=stack2[i];
    
  for(int i=0;i<n3;i++)
    sum3+=stack3[i];

    int p1=0,p2=0,p3=0;

    while(p1<n1 and p2<n2 and p3<n3)
    {
      if(sum1==sum2 and sum2==sum3)
      return sum1;
      if(sum1>=sum2 and sum1>=sum3)
      {
        sum1-=stack1[p1];
        p1++;
      }
      if(sum2>sum1 and sum2>=sum3)
      {
        sum2-=stack2[p2];
        p2++;
      }
      if(sum3>=sum2 and sum3>=sum1)
      {
        sum3-=stack3[p3];
        p3++;
      }
    }
    return -1;
} 
  

int main() 
{ 
    int stack1[] = { 3, 2, 1, 1, 1 }; 
    int stack2[] = { 4, 3, 2 }; 
    int stack3[] = { 1, 1, 4, 1 }; 
  
    int n1 = sizeof(stack1) / sizeof(stack1[0]); 
    int n2 = sizeof(stack2) / sizeof(stack2[0]); 
    int n3 = sizeof(stack3) / sizeof(stack3[0]); 
  
    cout << maxSum(stack1, stack2, stack3, n1, n2, n3) 
         << endl; 
    return 0; 
}A