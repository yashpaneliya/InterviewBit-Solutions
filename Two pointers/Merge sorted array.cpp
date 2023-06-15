// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

// Approach:
// 1. expand first array with 0s till it's size becomes m+n
// 2. start from end of both arrays and compare elements
// 3. if element of second array is greater, put it at the end of first array
// 4. else put element of first array at the end of first array and put 0 at the index of first array
// 5. if first array is exhausted, put all elements of second array in first array

void Solution::merge(vector<int> &A, vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    int i = 0, j = 0;

    while (j < n)
    {
        A.push_back(0);
        ++j;
    }

    j = n - 1;
    i = m - 1;
    int k = n + m - 1;

    while (i >= 0 && j >= 0)
    {
        if (B[j] > A[i])
        {
            A[k] = B[j];
            --j;
        }
        else
        {
            A[k] = A[i];
            A[i] = 0;
            --i;
        }
        --k;
    }

    while (j >= 0)
    {
        A[j] = B[j];
        --j;
    }
}

// TC: O(n)
// SC: O(1)