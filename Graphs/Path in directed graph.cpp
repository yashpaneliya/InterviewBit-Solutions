// https://www.interviewbit.com/problems/path-in-directed-graph/

// Approach:
// 1. We will use DFS to traverse the graph.
// 2. We will maintain a visited array to keep track of each node in the graph.
// 3. We will traverse the graph until we reach the destination node.

bool dfs(int start,vector<int>adj[],int vis[],int V)
{
    vis[start]=1;
    for(auto it:adj[start])
    {
        if(!vis[it])
        {
            if(it==V) return true;
             else
             {  vis[it]=1;
                if( dfs(it,adj,vis,V)==true)
                  return true;
             }
        }
    }
    return false;
}

int Solution::solve(int V, vector<vector<int> > &B) {
    vector<int> adj[V+1];
     int vis[V+1]={0};
     for(auto it:B)
     {
         adj[it[0]].push_back(it[1]);
     }
     if(dfs(1,adj,vis,V)) return 1;
     return 0;
}

// TC: O(V+E)
// SC: O(V)