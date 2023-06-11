// https://www.interviewbit.com/problems/convert-to-palindrome/

// Approach:
// check till what index, characters are matching at both ends
// if mismatch then
// first exclude the character from right end and check palindrome substring
// second exclude the character from left end and check palindrome substring
// if still none of them are not palindrome, that means we have to remove more than one characters to make it palindrome


// function to check palindrome from start to end index
bool checkPalindrome(string A, int start, int end)
{
    if (start == end)
        return true;
    if (start > end)
        return false;

    while (start <= end)
    {
        if (A[start] != A[end])
            return false;
        ++start;
        --end;
    }
    return true;
}

int Solution::solve(string A)
{
    int i = 0;
    int n = A.size();
    int j = n - 1;
    while (i < n && j >= 0)
    {
        if (A[i] == A[j])
            ++i, --j;
        else
        {
            if (checkPalindrome(A, i, j - 1) || checkPalindrome(A, i + 1, j))
                return true;
            else
                return false;
        }
    }
    return true;
}

// TC: O(n)
// SC: O(1)