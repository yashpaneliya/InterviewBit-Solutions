// https://www.interviewbit.com/problems/chain-of-pairs/

// Approach 1:
// recursively check for each possible combination to form the chain
// store max length of chain starting till each index in dp array

int dp[1001];

int util(vector<vector<int> > &A, int i){
    if(dp[i]!=-1) return dp[i];
    
    int maxlen=0;
    
    for(int j=i+1;j<A.size();++j)
        if(A[i][1] < A[j][0])
            maxlen = max(maxlen, util(A, j) + 1);
    
    return dp[i] = maxlen;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    
    for(int i=0;i<n;++i)
        dp[i]=-1;
    
    int res = 0;
    for(int i=0;i<A.size();++i)
        res = max(res, util(A, i) + 1);
    
    return res;
}

// TC: O(n^2)
// SC: O(n)