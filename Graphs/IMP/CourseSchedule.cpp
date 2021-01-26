// This problem is equivalent to detecting a cycle in the directed graph represented by prerequisites. Both BFS and DFS can be used to solve it using the idea of topological sort. Since pair<int, int> is inconvenient for implementing graph algorithms, we first transform it to the adjacency-list representation. If course u is a prerequisite of course v, then the adjacency list of u will contain v.

// BFS

// BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of its neighbors by 1. This process will be repeated for n (number of nodes) times.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> Graph(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            Graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> degree(numCourses,0);
        for(auto i:Graph)
        {
            for(int j:i)
            {
                degree[j]++;
            }
        }
        
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            while(j<numCourses and degree[j])
                j++;
            if(j==numCourses)
                return false;
            degree[j]--;
            for(int k:Graph[j])
            {
                degree[k]--;
            }
        }
        return true;
    }
};

