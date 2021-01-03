
#include <bits/stdc++.h>
using namespace std;

struct Item  
{ 
    int value, weight; 

    Item(int value, int weight) 
        : value(value) 
        , weight(weight) 
    { 
    } 
}; 
  

bool cmp(struct Item a, struct Item b) 
{ 
    return a.value/a.weight > b.value/b.weight ;
} 
  

double fractionalKnapsack(int W, vector<Item> &ar, int n) 
{ 
    sort(ar.begin(),ar.end(),cmp);
    int initialW=0;
    double initialV=0;
    for(int i=0;i<n;i++)
    {
      if(W-initialW > ar[i].weight )
      {
        initialW+=ar[i].weight;
        initialV+=ar[i].value;
      }
      else
      {
        int remain = W-initialW;
        initialV +=  ar[i].value * (double)remain/(double)ar[i].weight;
        break;
      }
    }
    return initialV;
} 
  
// Driver code 
int main() 
{ 
    int W = 50; //    Weight of knapsack 
    vector<Item> ar = { { 60, 10 }, { 100, 20 }, { 120, 30 } }; 
  
    int n = ar.size(); 
  
    // Function call 
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, ar, n); 
    return 0; 
}