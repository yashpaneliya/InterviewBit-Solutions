// https://www.interviewbit.com/problems/rotate-list/

// Approach:
// 1. Find the length of the list.
// 2. Find the node after which the list is to be rotated.
// 3. Break the list from that node and make it point to NULL.


ListNode *Solution::rotateRight(ListNode *A, int B)
{
    if (B == 0)
        return A;

    int n = 0;
    ListNode *temp = A;
    while (temp != NULL)
    {
        ++n;
        temp = temp->next;
    }
    // for B > n
    B = B % n;

    if (n == 1 || B == 0)
        return A;
    if (n == 1 && B == 1)
        return A;

    int stop = n - B;
    ListNode *breakpoint = A;
    ListNode *prev = NULL;

    while (stop--)
    {
        prev = breakpoint;
        breakpoint = breakpoint->next;
    }

    prev->next = NULL;
    ListNode *res = breakpoint;
    while (breakpoint->next != NULL)
        breakpoint = breakpoint->next;
    breakpoint->next = A;
    return res;
}

// TC: O(n)
// SC: O(1)