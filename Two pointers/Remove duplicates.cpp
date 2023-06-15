// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

// Approach 1:
// 1. start from index 1
// 2. Mark one pointer at index 0 and another at index 1
// 3. if both elements are same, increment second pointer
// 4. else store element at second pointer at index counter and increment counter and make first pointer equal to second pointer
// 5. return counter

int Solution::removeDuplicates(vector<int> &A)
{
    int i = 0, j = 0;
    int n = A.size();
    int cnt = 1;
    while (j < n)
    {
        if (A[i] == A[j])
            ++j;
        else
        {
            A[cnt] = A[j];
            ++cnt;
            i = j;
        }
    }
    return cnt;
}
