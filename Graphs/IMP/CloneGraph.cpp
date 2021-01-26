// Very IMP do watch a the techdose video,
// Basically we need to do DFS while making the copy of nodes and to keep a visited vector having the refrence to the nodes created to add them to subsequent nodes

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void DFS(Node *&node,vector<Node*> &visited)
    {
        Node* N = new Node(node->val);
        visited[node->val] = N;
        
        vector<Node*> temp = node->neighbors;
        
        for(int i=0;i<temp.size();i++)
        {
            int val = temp[i]->val;
            if(visited[val])
            {
                N->neighbors.push_back(visited[val]);
            }
            else
            {   
                DFS(temp[i],visited);
                N->neighbors.push_back(visited[val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        vector<Node*> visited(101,NULL);
        if(!node)
            return node;
        DFS(node,visited);
        
        return visited[node->val];
    }
};