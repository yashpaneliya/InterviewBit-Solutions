// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/hints/

// Approach:
// Recursively flatten the left and right subtrees
// If left subtree is NULL, flattern right subtree and return it
// If right subtree is NULL, flattern left subtree, put it on right and return it
// Else flatten both left and right subtrees, put left subtree on right of root and right subtree on the end of flattened left subtree

TreeNode* Solution::flatten(TreeNode* A) {
    if(A==NULL)
        return A;
    if(A->right==NULL && A->left==NULL)
        return A;
    if(A->right==NULL && A->left!=NULL)
    {
        A->right=flatten(A->left);
        A->left=NULL;
        return A;
    }
    if(A->right!=NULL && A->left==NULL)
    {
        A->right=flatten(A->right);
        A->left=NULL;
        return A;
    }
    else{
        TreeNode* l = flatten(A->left);
        TreeNode* r = flatten(A->right);
        A->right=l;
        TreeNode* temp=l;
        while(l->right!=NULL)
            l=l->right;
        l->right=r;
        A->left=NULL;
        return A;
    }
}

// TC: O(n)
// SC: O(n)