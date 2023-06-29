// https://www.interviewbit.com/problems/longest-common-subsequence/

// Approach:
// Maintain a dp array of size (m+1)*(n+1)
// dp[i][j] = LCS of A[0..i-1] and B[0..j-1]
// Top down approach
// if character matches then move both pointer by one place with increment in dp[i][j] by 1
// else take max of either of pointer moving one place ahead and keep other pointer at same place

int dp[1006][1006];

int util(string A, string B, int i, int j){
    if(i<0 || j<0) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(A[i]==B[j])
        return dp[i][j] = (util(A,B,i-1,j-1) + 1);
    else{
        dp[i][j] = max(util(A,B,i-1,j), util(A,B,i,j-1));
        return dp[i][j];
    }
}

int Solution::solve(string A, string B) {
    int m=A.size();
    int n=B.size();
    
    for(int i=0;i<=m;++i)
        for(int j=0;j<=n;++j)
            dp[i][j]=-1;
    
    return util(A,B,m-1,n-1);
}

// TC: O(m*n)
// SC: O(m*n) for dp array