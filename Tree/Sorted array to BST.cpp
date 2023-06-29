// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

// Approach:
// Perform partition like binary search and recursively call for left and right subarrays
// This will ensure that the tree is balanced

TreeNode* util(const vector<int> &A, int left, int right){
    if(left<=right){
        TreeNode* temp=(TreeNode *)malloc(sizeof(TreeNode));;
        int mid = left + (right-left) / 2;
        temp->val=A[mid];
        temp->left = util(A, left, mid-1);
        temp->right = util(A, mid+1, right);
        return temp;
    } else{
        return NULL;
    }
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return util(A, 0, A.size()-1);
}

// TC: O(logn)
// SC: O(logn) for recursive stack
