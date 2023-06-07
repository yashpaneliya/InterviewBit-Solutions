// https://www.interviewbit.com/problems/distribute-in-circle/

// Approach:
// Just try one example and put numbers according to given position.
// Our required answer will be at (A+C-1)%B

int solve(int A, int B, int C)
{
    return (A + C - 1) % B;
}

// TC: O(1)
// SC: O(1)