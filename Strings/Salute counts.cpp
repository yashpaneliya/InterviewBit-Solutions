// https://www.interviewbit.com/problems/salutes/hints/

// Approach:
// count number of '<' on the right side of each index
// multiply the count at each index of '>'
// add all the counts

long countSalutes(string A)
{
    // store number of '<' on the right side of each index
    int n = A.size();
    vector<int> rightCount(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        if (A[i] == '<')
            rightCount[i] = rightCount[i + 1] + 1;
        else
            rightCount[i] = rightCount[i + 1];
    }

    long res = 0;

    for (int i = 0; i < n; ++i)
    {
        if (A[i] == '>')
            res += rightCount[i];
    }
    return res;
}

// TC: O(n)
// SC: O(n)