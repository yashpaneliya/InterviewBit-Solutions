// https://www.interviewbit.com/problems/insertion-sort-list/

// Approach:
// Go till end of list using recursion
// and while backtracking, perform insertion sort down the list

void insertionSortUtil(ListNode *curNode)
{
    if (curNode == NULL)
        return;

    insertionSortUtil(curNode->next);

    ListNode *prev = curNode;
    while (curNode->next != NULL)
    {
        if (curNode->val > curNode->next->val)
        {
            swap(curNode->val, curNode->next->val);
        }
        else
        {
            break;
        }
        curNode = curNode->next;
    }
}

ListNode *Solution::insertionSortList(ListNode *A)
{
    if (A == NULL || A->next == NULL)
        return A;
    insertionSortUtil(A);
    return A;
}

// TC: O(n^2)
// SC: O(1)