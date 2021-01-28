#include <bits/stdc++.h>
using namespace std;

class Edge 
{
public:
    int src, dest;
};

class Graph 
{
public:
    int V, E;
    Edge* edge;
};

int find(vector<int> &dis,int x)
{
  if(dis[x]==-1)
  return x;
  return find(dis,dis[x]);
}

void Union(int x,int y,vector<int> &dis)
{
  dis[x]=y;
}

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;
 
    graph->edge = new Edge[graph->E * sizeof(Edge)];
 
    return graph;
}
 
int isCycle(Graph* graph)
{
    vector<int> dis(graph->V,-1);
    for(int i=0;i<graph->E;i++)
    {
      int x = find(dis,graph->edge[i].src);
      int y = find(dis,graph->edge[i].dest);
      if(x==y)
      return 1;
      Union(x,y,dis);
    }
    return 0;
}
 
int main()
{
    /* Let us create the following graph
        0
        | \
        |  \
        1---2 */
    int V = 3, E = 3;
    Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";
 
    return 0;
}