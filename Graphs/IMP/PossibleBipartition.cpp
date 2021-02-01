class Solution {
public:
    
    void debGraph(vector<vector<int>> &graph)
    {
        cout<<"////////////////"<<endl;
        for(int i=0;i<graph.size();i++)
        {
            cout<<"("<<i<<")   ";
            for(int j=0;j<graph[i].size();j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"////////////////"<<endl;
        
    }
    
    bool bfs(vector<int> &color,vector<vector<int>> graph,int N)
    {
        queue<int> Q;
        Q.push(N);
        color[N]=0;
        
        while(!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            int c = color[x]; 
            cout<<x<<" ";
            for(int i=0;i<graph[x].size();i++)
            {
                int ind = graph[x][i];
                if(color[ind]==c)
                    return false;
                if(color[ind]==-1)
                {
                    color[ind]=abs(c-1);
                    Q.push(ind);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        vector<int> color(N+1,-1);
        
        for(auto i:dislikes)
        {
            graph[i[0]].push_back(i[1]);
        }
        debGraph(graph);
        for(int i=1;i<=N;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(color,graph,i))
                    return false;
            }
        }
        return true;
    }
};