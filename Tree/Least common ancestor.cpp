// https://www.interviewbit.com/problems/least-common-ancestor/

// Approach:
// Find if both nodes are present in the tree
// If yes, then find the LCA
// Check if value of node equals to any of the two values
// If yes, then return that node
// Else, recursively call for left and right subtrees
// If both left and right subtrees return non NULL value, then return current node as LCA
// Else, return the non NULL value

bool dfs(TreeNode* A, int x){
    if(A==NULL) return false;
    if(A->val==x) return true;
    if(dfs(A->left,x) || dfs(A->right,x)) return true;
    return false;
}

TreeNode* util(TreeNode* A, int B, int C){
    if(A==NULL) return NULL;
    
    if(A->val==B || A->val==C){
        return A;
    }
    
    TreeNode* l = util(A->left,B,C);
    TreeNode* r = util(A->right,B,C);
    
    if(l && r){
        return A;
    }
    if(l)
        return l;
    return r;
}

int Solution::lca(TreeNode* A, int B, int C) {
    if(dfs(A,B) && dfs(A,C))
    {
        TreeNode* t = util(A,B,C);
        return t->val;
    }
    return -1;
} 

// TC: O(n)
// SC: O(height) for recursive stack