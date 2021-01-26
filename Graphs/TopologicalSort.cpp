// A C++ program to print topological 
// sorting of a DAG 
#include <bits/stdc++.h> 
using namespace std; 
  
class Graph { 

    int V; 

    list<int>* adj; 
  
    void topologicalSortUtil(int v, bool visited[], 
                             stack<int>& Stack); 
  
public: 

Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void addEdge(int v, int w) 
{ 
    // Add w to v’s list. 
    adj[v].push_back(w); 
} 

void DFS(int node,vector<bool> &visited,stack<int> &ST)
{
  visited[node]=1;
  for(auto i=adj[node].begin();i!=adj[node].end();i++)
  {
    if(!visited[*i])
    {
      DFS(*i,visited,ST);
    }
  }
  ST.push(node);
}

void topologicalSort() 
{ 
    vector<bool> visited(V,false);
    visited[0] = 1;
    stack<int> ST;
    for(int i=0;i<V;i++)
    {
      DFS(i,visited,ST);
    }
    while(!ST.empty())
    {
      cout<<ST.top()<<" ";
      ST.pop();
    }
  return;
} 
}; 
  
// Driver Code 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given "
            "graph \n"; 
    
    // Function Call 
    g.topologicalSort(); 
  
    return 0; 
}