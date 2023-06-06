// https://www.interviewbit.com/problems/perfect-peak-of-array/


// Approach:
// iterate over the array and store the maximum element seen till current index in an array
// iterate over the array from the end and store the minimum element seen till current index in an array
// iterate over the array and check if the current element is greater than the maximum element seen till current index and less than the minimum element seen till current index
// if such an element is found, return 1
// if no such element is found, return 0

int perfectPeak(vector<int> &A)
{
    int n = A.size();
    vector<int> cumMax(n, 0);
    vector<int> cumMin(n, 0);
    cumMax[0] = A[0];
    for (int i = 1; i < n; ++i)
    {
        if (cumMax[i - 1] > A[i])
            cumMax[i] = cumMax[i - 1];
        else
            cumMax[i] = A[i];
    }

    cumMin[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        if (cumMin[i + 1] > A[i])
            cumMin[i] = A[i];
        else
            cumMin[i] = cumMin[i + 1];
    }

    for (int i = 1; i < n - 1; ++i)
        if (cumMax[i - 1] < A[i] && cumMin[i + 1] > A[i])
            return 1;
    return 0;
}

// TC: O(n)
// SC: O(n)