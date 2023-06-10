// https://www.interviewbit.com/problems/atoi/

// Approach:
// check for negative/positive number cases using -/+ sign in the beginning
// check for digit inputs
// if any invalid input/whitespace occur in between, break the loop
// generate the number using the string by multiplying each digit with 10^(its position)
// check for overflow/underflow cases

int Solution::atoi(const string A)
{
    string s = "";
    bool neg = false;
    for (int c = 0; c < A.size(); ++c)
    {
        if ((A[c] - '0') >= 0 && (A[c] - '0') <= 9)
            s += A[c];
        else if (A[c] == '-' && s.size() == 0 && (A[c + 1] - '0') >= 0 && (A[c + 1] - '0') <= 9)
            neg = true;
        else if (A[c] == '+' && s.size() == 0 && (A[c + 1] - '0') >= 0 && (A[c + 1] - '0') <= 9)
            continue;
        else
            break;
    }

    int len = s.size();

    if (len == 0)
        return 0;
    if (len > 10 && neg == true)
        return INT_MIN;
    if (len > 10 && neg == false)
        return INT_MAX;

    long long res = 0;
    for (int i = 0; i < len; ++i)
    {
        res += (s[i] - '0') * pow(10, len - i - 1);
    }

    if (neg)
        res = -1 * res;

    if (res < INT_MIN)
        return INT_MIN;
    if (res > INT_MAX)
        return INT_MAX;
    return res;
}

// TC: O(n)
// SC: O(1)