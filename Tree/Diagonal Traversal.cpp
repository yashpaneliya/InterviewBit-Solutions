// https://www.interviewbit.com/problems/diagonal-traversal/

// Approach:
// 

vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*>q;
    vector<int>ans;
    if(A==NULL)return ans;
    q.push(A);
    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        while(curr!=NULL)
        {
            ans.push_back(curr->val);
            if(curr->left!=NULL)q.push(curr->left);
            curr = curr->right;
        }
    }
    return ans;
}