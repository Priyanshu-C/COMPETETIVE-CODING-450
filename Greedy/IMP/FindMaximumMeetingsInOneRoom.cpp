
#include <bits/stdc++.h> 
using namespace std; 
 
struct meeting { 
    int start; 
    int end; 
    int pos; 
}; 
 
bool comparator(struct meeting m1, meeting m2) 
{ 
    return m1.end < m2.end;
} 

void maxMeeting(vector<int> &S,vector<int> &F, int n) 
{ 
    vector<meeting> M(n);
    for(int i=0;i<n;i++)
    {
      M[i].start = S[i];
      M[i].end = F[i];
      M[i].pos = i+1;
    }
    sort(M.begin(),M.end(),comparator);
    int limit = M[0].end; 
    vector<int> ar;
    ar.push_back(M[0].pos);
    for(int i=1;i<n;i++)
    {
      if(limit <= M[i].start)
      {
        ar.push_back(M[i].pos);
        limit = M[i].end;
      }
    }
    for(int i:ar)
    cout<<i<<" ";
    cout<<endl;
} 

int main() 
{ 

    vector<int> S = { 1, 3, 0, 5, 8, 5 }; 
     

    vector<int> F = { 2, 4, 6, 7, 9, 9 }; 
     

    int n = S.size();
 

    maxMeeting(S, F, n); 
 
    return 0; 
} 