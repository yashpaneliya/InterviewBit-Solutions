// https://www.interviewbit.com/problems/invert-the-binary-tree/

// Approach:
// Recursively swap the left and right child of each node

TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL) return NULL;
    
    TreeNode* temp=A->left;
    A->left=A->right;
    A->right=temp;
    
    invertTree(A->left);
    invertTree(A->right);
    
    return A;
}

// TC: O(N)
// SC: O(1)