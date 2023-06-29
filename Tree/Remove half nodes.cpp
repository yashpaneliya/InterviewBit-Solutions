// https://www.interviewbit.com/problems/remove-half-nodes/discussion/p/simplest-code-using-recursion/406561/1891/

// Approach:
// Find complete node in left and right subtrees and replace it with current node's left and right
// Do this recursively.
// This will remove all half nodes by just skipping them while backtracking.

TreeNode* Solution::solve(TreeNode* A) {
    if(A==NULL) return A;
    
    if(A->left == NULL && A->right==NULL)
        return A;
        
    if(A->left==NULL)
        return solve(A->right);
    if(A->right==NULL)
        return solve(A->left);
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
}

// TC: O(n)
// SC: O(1) / O(height) for recursive stack 