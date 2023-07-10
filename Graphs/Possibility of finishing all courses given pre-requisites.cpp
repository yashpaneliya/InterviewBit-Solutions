// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

// Approach:
// 1. We will use DFS to traverse the graph.
// 2. We will maintain a visited array to keep track of each node in the graph.
// 3. Basically we want to check if there is a cycle in the graph or not.
// 4. If there is a cycle in the graph then we will return false as final answer.

bool checkcycle(int node, vector<int> adj[], vector<int> &visited){
    visited[node]=2;
    for(int v:adj[node]){
        if(!visited[v])
        {    if(checkcycle(v, adj, visited)) 
                return true;}
        else if(visited[v]==2)
            return true;
    }
    visited[node]=1;
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int> adj[A+1];
    vector<int> visited(A+1,0);
    
    for(int i=0;i<B.size();++i){
        adj[B[i]].push_back(C[i]);
    }
    
    for(int i=1;i<=A;++i){
        if(checkcycle(i, adj, visited)) // if cycle found
            return 0;
    }
    return 1;
}

// TC: O(V+E)
// SC: O(V)