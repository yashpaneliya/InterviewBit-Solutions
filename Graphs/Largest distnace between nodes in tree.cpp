// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

// Approach:
// 1. We will use DFS to find the height of each node.
// 2. We will maintain a variable ans to keep track of the maximum distance between two nodes.
// 3. We will find the maximum height of each node and update the ans variable.
// 4. We will repeat the above steps until we reach the leaf node.

int height(int node, vector<vector<int>> &adj, int &ans){
    int maxi = 0;
    for(auto it : adj[node]){
        int nextHeight = height(it, adj, ans);
        ans = max(ans, maxi + nextHeight);
        maxi = max(maxi, nextHeight);
    }
    return 1 + maxi;
}

int Solution::solve(vector<int> &A) {
    vector<vector<int>> adj(A.size(), vector<int>(0));
    int root = -1;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == -1){
            root = i;
            continue;
        }
        adj[A[i]].push_back(i);
    }
    
    int ans=0;
    height(root, adj, ans);
    return ans;
}

// TC: O(V+E)
// SC: O(V)