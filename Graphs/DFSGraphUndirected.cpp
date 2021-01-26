
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; 

    list<int>* adj;

    void DFSUtil(int v, vector<bool> &visited);
 
public:
    Graph(int V); 
 
    void addEdge(int v, int w);
 
    void DFS(int v);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v, vector<bool> &visited)
{
  visited[v]=true;
  cout<<v<<" ";
  for(int i:adj[v])
  {
    if(!visited[i])
    DFSUtil(i,visited);
  }
}
 

void Graph::DFS(int v)
{
   vector<bool> visited(V,false);
   DFSUtil(v,visited);
}
 
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}