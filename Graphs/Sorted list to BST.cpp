// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/hints/

// Approach:
// Fast and Slow pointer approach
// 1. We will use Fast and Slow pointer approach to find the middle element of the linked list.
// 2. We will make the middle element as the root of the tree.
// 3. We will recursively call the function for the left and right half of the linked list.

TreeNode* buidlTree(ListNode* start, ListNode *end){
    if(start==end) return NULL;
    
    ListNode *slow=start;
    ListNode *fast=start;
    
    while(fast!=end && fast->next!=end){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    TreeNode* root=new TreeNode(slow->val);
    root->left = buidlTree(start, slow);
    root->right = buidlTree(slow->next, end);
    
    return root;
} 
 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    return buidlTree(A, NULL);
}

// TC: O(N)
// SC: O(N)