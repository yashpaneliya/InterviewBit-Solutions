// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

// Approach:
// Do level order traversal and store the nodes in a map with key as level
// Take a vector of vectors and push the vectors from map to it
// This will ensure that the vectors are sorted from left most level
// for each node in queue, push its left and right nodes with level-1 and level+1 respectively

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    queue<pair<TreeNode*,int>> q; // Node, level
    map<int, vector<int>> levels; // taken sorted map to get vectors from left most level
    vector<vector<int>> res;

    if(A==NULL) return res;
    
    q.push({A,0});
    
    while(!q.empty()){
        TreeNode* temp=q.front().first;
        int level = q.front().second;
        
        q.pop();
        
        levels[level].push_back(temp->val);
        
        if(temp->left) q.push({temp->left,level-1});
        if(temp->right) q.push({temp->right,level+1});
    }
    
    for(auto mapEle:levels){
        res.push_back(mapEle.second);
    }
    return res;
}

// TC: O(n)
// SC: O(n) for queue and map