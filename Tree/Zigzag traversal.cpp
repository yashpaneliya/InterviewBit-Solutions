// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/hints/

// Approach:
// Use a queue to store the nodes of the current level
// Use a flag to indicate whether the current level is to be traversed left to right or right to left
// If flag is true, traverse left to right, else traverse right to left

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> res;
    
    queue<TreeNode*> q;
    
    q.push(A);
    
    bool flag=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> temp;
        while(size--){
            int top = q.front()->val;
            temp.push_back(top);    
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
        }
        if(flag){
            res.push_back(temp);
        } else{
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        flag=!flag;
    }
    
    return res;
}

// TC: O(N)
// SC: O(N)