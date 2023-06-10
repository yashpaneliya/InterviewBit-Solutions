// https://www.interviewbit.com/problems/remove-consecutive-characters/

// Approach:
// iterate over the string and check if the current character is same as the previous character
// if yes, then store character to temp string and increment the count of temp string length
// else check if the count=B, then reset the count else append it to final result and reset the count and temp string

string Solution::solve(string A, int B)
{
    int n = A.size();
    int count = 1;
    string res = "";

    int i;
    string temp = "";
    temp += A[0];
    for (i = 1; i < n; ++i)
    {
        if (A[i] == A[i - 1])
        {
            temp += A[i];
            ++count;
        }
        else
        {
            if (count != B)
            {
                res += temp;
            }
            temp = A[i];
            count = 1;
        }
    }
    if (count != B)
    {
        res += temp;
    }
    return res;
}

// TC: O(n)
// SC: O(n)