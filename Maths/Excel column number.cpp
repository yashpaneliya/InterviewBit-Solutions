// https://www.interviewbit.com/problems/excel-column-number/

// Approach:
// 1. Find the length of string
// 2. Count the already passed character indexes for excel sheet
// 3. Add the current character index to the count
// 4. return the count

int titleToNumber(string A)
{
    int n = A.size();
    if (n == 1)
        return A[0] - 'A' + 1;
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        num += ((A[i] - 'A' + 1) * pow(26, n - i - 1));
    }
    return num;
}

// TC: O(nlogn)
// SC: O(1)