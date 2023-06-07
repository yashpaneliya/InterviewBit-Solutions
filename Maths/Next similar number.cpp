// https://www.interviewbit.com/problems/next-similar-number/

// Approach:
// 1. Find the break point from the right end of the string where non-decreasing order breaks
// 2. Find the just higher number then number at breakPoint and swap them.
// 3. Sort the substring after break point index

string solve(string A)
{
    int n = A.size();
    if (n == 1)
        return "-1";
    int mi = n - 1;
    int i;
    // finding from which position non-decreasing order breaks (from the right end of string)
    for (i = n - 2; i >= 0; --i)
    {
        if (A[i] < A[i + 1])
        {
            break;
        }
    }

    if (i == -1)
        return "-1";
    // find the just higher number then number at breakPoint and swap them.
    for (int j = n - 1; j > i; --j)
    {
        if (A[j] > A[i])
        {
            swap(A[j], A[i]);
            break;
        }
    }
    // sort the substring after break point
    sort(A.begin() + i + 1, A.end());
    return A;
}

// TC: O(nlogn)
// SC: O(n)