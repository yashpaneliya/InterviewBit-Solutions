// Problem link: https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

// Approach:
// find min and max element
// return sum of them

int solve(vector<int> &A)
{
    int maxEle = INT_MIN;
    int minEle = INT_MAX;
    for (int x : A)
    {
        maxEle = max(maxEle, x);
        minEle = min(minEle, x);
    }
    return maxEle + minEle;
}

// TC: O(n)
// SC: O(1)