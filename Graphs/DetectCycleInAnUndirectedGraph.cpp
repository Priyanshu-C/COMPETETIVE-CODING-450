#include <bits/stdc++.h>
using namespace std;
class Graph
{
  private:
  vector<vector<int>> store;
  int size;
  public:
  Graph(int V)
  {
    size = V;
    store.resize(V);
  }
  void addEdge(int u,int v)
  {
    store[u].push_back(v);
    store[v].push_back(u);
  }

  bool DFSUtil(int u,vector<bool> &visited,int parent)
  {
    cout<<u<<" ";
    visited[u]=1;
    for(int i=0;i<store[u].size();i++)
    {
      int key = store[u][i];
      if(!visited[key])
      {
        if(!DFSUtil(key,visited,u))
        return false;
      }
      else if(parent!=key)
      {
        return false;
      }
    }
    return true;
  }
  
  bool detectCycle()
  {
    vector<bool> visited(size,false);
    for(int i=0;i<size;i++)
    {
      if(!visited[i])
      if(!DFSUtil(i,visited,-1))
      return true;
    }
    return false;
  }
};

int main() {

     Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.detectCycle()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
  
}