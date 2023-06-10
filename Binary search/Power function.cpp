// https://www.interviewbit.com/problems/implement-power-function/discussion/p/vv-easy-c-soln/57244/773/

// Approach:
// X^n = (X^(n/2))^2 if n is even
// X^n = X*(X^(n/2))^2 if n is odd

int Solution::pow(int x, int n, int d)
{
    if (x == 0 || d == 1)
        return 0;
    if (x == 1 || n == 0)
        return 1;

    long long int res = 1;
    long long int parts = x;
    while (n)
    {
        if (n % 2)
            res = (res * parts) % d;
        parts = (parts * parts) % d;
        n = n / 2;
    }
    if (res < 0)
    {
        res = (d - abs(res) % d);
        return res;
    }
    return res;
}

// TC: O(logn)
// SC: O(1)