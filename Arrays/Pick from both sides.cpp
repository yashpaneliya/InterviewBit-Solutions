// Problem Link: https://www.interviewbit.com/problems/pick-from-both-sides/

// Approach:

// We take either 0 to B-1 elements from left or B elements from right end
// We can also select some initial x elements from left and remaining B-x from right

// To do so, we first compute sum of B elements from left ans store it as our answer
// Then set i=B-1 and j=right end of array (n-1)
// take out ith element from sum and add jth element to sum.
// compare it with answer and update answer if sum > answer
// i-- and j--

int solve(vector<int> &A, int B)
{
    int ans = INT_MIN;
    int i = 0;
    int sum = 0;
    for (i = 0; i < B; ++i)
        sum += A[i];
    i = B - 1;
    int j = A.size() - 1;
    ans = max(sum, ans);
    while (i >= 0)
    {
        sum -= A[i];
        sum += A[j];
        --j;
        --i;
        ans = max(ans, sum);
    }
    return ans;
}

// TC: O(B)
// SC: O(1)