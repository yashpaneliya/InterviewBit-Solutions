// https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

// Approach:
// Reverse k nodes and skip k nodes alternatively

ListNode *reverseList(ListNode *head, int k, bool isreverse)
{
    if (head == NULL)
        return head;
    int count = k;
    // check alternate lists
    if (isreverse == true)
    {
        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        // reverse k nodes
        while (k-- && cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // first node's next will be the next unreversed k nodes from list
        head->next = reverseList(cur, count, false);
        return prev;
    }
    else
    {
        // skip k nodes
        ListNode *prev = head;
        k--;
        while (k-- && head != NULL)
        {
            head = head->next;
        }
        // kth node's next will be next reversed k nodes
        head->next = reverseList(head->next, count, true);
        return prev;
    }
}

ListNode *Solution::solve(ListNode *A, int B)
{
    return reverseList(A, B, true);
}

// TC: O(n)
// SC: O(1)