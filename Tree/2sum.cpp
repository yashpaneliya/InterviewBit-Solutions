// https://www.interviewbit.com/problems/2sum-binary-tree/hints/

// Approach:
// Use a hash table to keep track of the nodes that have been visited
// For each node, check if B - node->val is present in the hash table

unordered_map<int, bool> tracker;

int util(TreeNode* A, int B){
    if(A==NULL) return 0;
    
    if(tracker[B - A->val]==true) 
        return 1;
        
    tracker[A->val]=true;
    
    if(A->val > B)
        return util(A->left, B);
    else{
        return util(A->left, B) | util(A->right, B);
    } 
}

int Solution::t2Sum(TreeNode* A, int B) {
    tracker.clear();
    return util(A,B);
}

// TC: O(N)
// SC: O(N)