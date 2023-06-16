// https://www.interviewbit.com/problems/list-cycle/

// Approach:
// 1. Traverse the list and mark the nodes as visited by making their value negative.
// 2. If a node is visited again, it means there is a cycle.
// 3. Return the node where the cycle begins.

ListNode *Solution::detectCycle(ListNode *A)
{
    while (A != NULL)
    {
        if (A->val < 0)
        {
            A->val = -1 * A->val;
            return A;
        }
        else
        {
            A->val = A->val * -1;
            A = A->next;
        }
    }
    return NULL;
}

// TC: O(n)
// SC: O(1)