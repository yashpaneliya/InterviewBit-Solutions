// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

// Approach:
// 1. Traverse the list and if the current node's value is equal to the next node's value, skip the next node.
// 2. Else, make the current node point to the next node and move the current node to the next node.

ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curnode=A;
    ListNode* temp=A;
    
    while(A!=NULL){
        if(A->val==curnode->val)
            A=A->next;
        else{
            curnode->next=A;
            curnode=A;
            A=A->next;
        }
    }
    curnode->next=NULL;
    return temp;
}

// TC: O(n)
// SC: O(1)