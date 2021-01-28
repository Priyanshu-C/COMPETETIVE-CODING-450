#include <bits/stdc++.h> 
using namespace std; 

#define V 5

int minW(vector<int> &dist,vector<bool> &processed)
{
  int minValue = INT_MAX;
  int minIndex = 0;
  for(int i=0;i<V;i++)
  {
    if(!processed[i] and minValue > dist[i] )
    {
      minValue = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void print(vector<int> parent,int graph[V][V])
{
   cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}

void primMST(int graph[V][V])
{
  vector<int> dist(V,INT_MAX);
  vector<bool> processed(V,false);
  vector<int> parent(V);

  dist[0] = 0;
  parent[0]=-1;
  for(int i=0;i<V-1;i++)
  {
    int index = minW(dist,processed);
    processed[index] = 1;
    for(int j=0;j<V;j++)
    {
      if(graph[index][j] and !processed[j] and dist[j] > graph[index][j])
      {
        parent[j]=index;
        dist[j] = graph[index][j];
      }
    }
  }
  print(parent,graph);

}


int main()  
{  
    /* Let us create the following graph  
        2 3  
    (0)--(1)--(2)  
    | / \ |  
    6| 8/ \5 |7  
    | / \ |  
    (3)-------(4)  
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    // Print the solution  
    primMST(graph);  
  
    return 0;  
}  