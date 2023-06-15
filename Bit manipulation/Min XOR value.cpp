// https://www.interviewbit.com/problems/min-xor-value/

// Approach 1:
// 1. Sort the array
// 2. Find the min XOR of adjacent elements
// Why? Because if we sort the array, the numbers which are close to each other will have min XOR due to only 1 bit difference is most of the adjacent numbers

int Solution::findMinXor(vector<int> &A)
{
    int n = A.size();
    int ans = INT_MAX;
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 1; i++)
        ans = min(ans, A[i] ^ A[i + 1]);
    return ans;
}

// TC: O(n)
// SC: O(1)