#include <bits/stdc++.h>
using namespace std;
// Graph using Adjacency Matrix

class GraphAM{
private:
  vector<vector<int>> store;
  int n,m;
public:
  GraphAM (int x)
  {
    n=x;
    store.resize(n,vector<int>(n,0)); 
  }
  void addEdge(int u,int v)
  {
    store[u][v] = 1;
    store[v][u] = 1;
  }
  void printGraph()
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<store[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};


class GraphAL{
private:
  vector<vector<int>> store;
  int n,m;
public:
  GraphAL (int x)
  {
    n=x;
    store.resize(n); 
  }
  void addEdge(int u,int v)
  {
    store[u].push_back(v);
    store[v].push_back(u);
  }
  void printGraph()
  {
    for(int i=0;i<n;i++)
    {
      cout<<"Vertex "<<i<<endl;
      for(int val:store[i])
      {
        cout<<val<<" ";
      }
      cout<<endl;
    }
  }
};


int main() {
  GraphAL nG(10);
  nG.addEdge(4, 5);
  nG.addEdge(5, 5);
  nG.addEdge(2, 2);
  nG.printGraph();
}

