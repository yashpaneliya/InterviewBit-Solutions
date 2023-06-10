// https://www.interviewbit.com/problems/implement-strstr/

// Approach:
// brute force approach
// check if B is a substring of A starting from each index of A
// can be improved using Rabin-Karp and KMP algo

bool issubstr( string A, string B, int i){
   
    for(int j=0; j<B.size(); j++){
        if(A[i+j]!= B[j])
            return false;
    }
   
    return true;
   
}

int Solution::strStr(const string A, const string B) {
    for(int i=0; i<A.size(); i++){
        if(issubstr(A,B,i))
            return i;
    }
    return -1;
}

// TC: O(n*m)
// SC: O(1)