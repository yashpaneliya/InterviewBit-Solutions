// https://www.interviewbit.com/problems/reverse-bits/

// Approach:
// Do AND with the number with 1
// Left shift the result by 1
// OR the result with the last bit of the number (received from AND operation)
// Right shift the original number by 1 to get next digit in next iteration
// Repeat the process until the number becomes 0
// Add trailing zeros to the result to make it 32 bit

unsigned int Solution::reverse(unsigned int A) { 
    int count=0;
    unsigned int res=0;
    
    while(A!=0)
    {
        res = (res<<1) | (A & 1);
        ++count;
        A=A>>1;
    }
    res = res << (32-count);
    return res;
}

// TC: O(n)
// SC: O(1)