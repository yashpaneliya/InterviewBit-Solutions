// https://www.interviewbit.com/problems/number-of-1-bits/

// Approach :
// Example:
//   100001011
// & 000000001
//   000000001

//   100001010
// & 000000001
//   000000000

// As we can see that if we do AND of a number with 1 then we get the last bit of that number.
// So we can do AND of the number with 1 and then right shift the number by 1 bit and repeat the process until the number becomes 0.

int Solution::numSetBits(unsigned int A)
{
    int count = 0;
    while (A != 0)
    {
        if (A & 1)
            ++count;
        A = A >> 1;
    }
    return count;
}

// TC: O(n)
// SC: O(1)