// https://www.interviewbit.com/problems/addition-without-summation/

// Approach:
// Formula for A+B
// A+B = (A^B) + (A&B)<<1

int addNumbers(int A, int B) {
    if(A==0) return B;
    if(B==0) return A;
    
    return addNumbers(A^B, (A&B)<<1);
}