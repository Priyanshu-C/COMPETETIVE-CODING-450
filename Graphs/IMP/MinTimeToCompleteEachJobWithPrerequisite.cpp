
#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

vector<vector<int>> graph;
vector<int> indegree;

void addEdge(int u,int v)
{
  graph[u].push_back(v);
  indegree[v]++;
}

void printOrder(int n,int m)
{
  vector<int> RES(n+1,INT_MIN);
  queue<int> q;
  for(int i=0;i<n;i++)
  {
    if(!indegree[i])
    {
      q.push(i);
      RES[i]=1;
    }
  }
  while(!q.empty())
  {
    int curr = q.front();
    q.pop();
    for(int i:graph[curr])
    {
      indegree[i]--;
      if(RES[i] < 1 + RES[curr] )
      {
        RES[i] = 1 + RES[curr];
      }
      if(indegree[i]==0)
      q.push(i);
    }
   }
   for(int i:RES)
   cout<<i<<" ";

}

int main()
{
    int n, m;
    n = 10;
    m = 13;
    indegree.resize(n);
    graph.resize(n);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
 
    // Function Call
    printOrder(n, m);
    return 0;
}