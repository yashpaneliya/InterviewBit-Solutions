// https: // www.interviewbit.com/problems/3-sum/

// Approach:
// 1. sort the array
// 2. fix one element and check for other two in two pointer approach with left and right
// 3. if sum > B then check for abs. difference with minimum difference and then move right pointer to left
// 4. if sum < B then check for abs. difference with minimum difference and then move left pointer to right

int Solution::threeSumClosest(vector<int> &A, int B)
{
    int n = A.size();

    int mindiff = INT_MAX;

    sort(A.begin(), A.end());

    int j, k;
    int sum;
    int res;
    int diff;

    // fixing one element and checking for other two in two pointer approach with left and right
    for (int i = 0; i < n - 2; ++i)
    {
        left = i + 1;
        right = n - 1;
        while (left < right)
        {
            sum = A[i] + A[left] + A[right];
            diff = B - sum;
            if (diff == 0)
                return B;
            else if (diff < 0)
            {
                // if sum > B then check for abs. difference with minimum difference and then move right pointer to left
                if (abs(diff) < mindiff)
                {
                    mindiff = abs(diff);
                    res = sum;
                }
                --right;
            }
            else
            {
                // if sum < B then check for abs. difference with minimum difference and then move left pointer to right
                if (abs(diff) < mindiff)
                {
                    mindiff = abs(diff);
                    res = sum;
                }
                ++left;
            }
        }
    }
    return res;
}

// TC: O(n^2)
// SC: O(1)