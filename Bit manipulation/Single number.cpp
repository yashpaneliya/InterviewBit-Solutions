// https://www.interviewbit.com/problems/single-number/

// Approach 1:
// XOR of same numbers = 0
// So during traversal those number will make up to 0 and the single number will not
// so that will be our answer

int Solution::singleNumber(const vector<int> &A) {
    int res=0;
    for(int x:A)
        res = res^x;
    return res;
}

// TC: O(n)
// SC: O(1)