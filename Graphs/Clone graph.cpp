// https://www.interviewbit.com/problems/clone-graph/

// Approach:
// 1. We will use BFS to traverse the graph.
// 2. We will maintain a queue to keep track of each node in the graph.
// 3. We will maintain a hash to keep track of which node has already created and coming again in path.
// 4. If the node value appearing first time then register it to hash and create a new node and push it to queue.
// 5. If the node value is already present in the hash then just push the node to the neighbors of the current node.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    // to keep track of which node has already created and coming again in path
    unordered_map<int, UndirectedGraphNode*> nodehash;
    
    // maintaining queue just to keep track of each node in graph
    queue<UndirectedGraphNode *> q;
    q.push(node);
    
    UndirectedGraphNode * root=new UndirectedGraphNode(node->label);
    nodehash[node->label] = root;
    
    while(!q.empty()){
        UndirectedGraphNode* t=q.front();
        q.pop();
        
        for(auto v:t->neighbors){
            // if node value appearing first time then register it to hash and create a new node
            // push it to queue 
            if(nodehash[v->label]==NULL){
                nodehash[v->label] = new UndirectedGraphNode(v->label);
                q.push(v);
            }
            (nodehash[t->label]->neighbors).push_back(nodehash[v->label]);
        }
    }
    
    return nodehash[node->label];
}

// TC: O(V+E)
// SC: O(N)