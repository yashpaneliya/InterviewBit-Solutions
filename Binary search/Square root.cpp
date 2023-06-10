// https://www.interviewbit.com/problems/square-root-of-integer/

// Approach:
// Binary search
// Search in binary search manner and check whether mid*mid is less than or equal to and (mid+1)*(mid+1) is greater than A
// if yes, then return mid
// if mid*mid is greater than A, then search in left half
// else search in right half


void butil(long long start, long long end, int num, long long &ans)
{
    long long mid = start + (end - start) / 2;
    if (start <= end)
    {
        if ((mid * mid) <= num && (mid + 1) * (mid + 1) > num)
        {
            ans = mid;
            return;
        }
        if ((mid * mid) > num)
            butil(start, mid - 1, num, ans);
        else
        {
            butil(mid + 1, end, num, ans);
        }
    }
}
int Solution::sqrt(int A)
{
    if (A == 0)
        return 0;
    if (A == 1)
        return 1;
    long long ans = 1;
    butil(0, A / 2, A, ans);
    return (int)ans;
}

// TC: O(logn)
// SC: O(1)