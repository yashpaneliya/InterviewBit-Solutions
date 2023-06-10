// https://www.interviewbit.com/problems/matrix-search/

// Approach:
// find the row in which the target element can be present by checking the last element of each row
// then apply binary search on that row

bool bsearch(vector<int> &arr, int start, int end, int target)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] > target)
            return bsearch(arr, start, mid - 1, target);
        else
            return bsearch(arr, mid + 1, end, target);
    }
    else
        return false;
}
int Solution::searchMatrix(vector<vector<int>> &A, int B)
{
    int row = A.size();
    int col = A[0].size();
    int rn = 0;
    for (int i = 0; i < row; ++i)
    {
        if (A[i][col - 1] >= B)
        {
            rn = i;
            break;
        }
    }

    return bsearch(A[rn], 0, col - 1, B);
}

// TC: O(n + log(m)) // can be improved to O(log(n) + log(m)) using binary search in rows also
// SC: O(1)