// https://www.interviewbit.com/problems/evaluate-expression-to-true/

// Approach:
// We count the number of ways to parenthesize the expression such that it evaluates to true or false.
// For each operator we count the ways to be true and false separately.
// We count all the combination to make complete expression True
// there might some false subexpression possible which make whole expression True
// we also have to consider them
// We pass a target value to achieve and return the number of ways to achieve that target value based on the operator

int mod = 1003;
int dp[151][151][2];

int solve(string exp, int start, int end, int target){
    if(start>end) return 0;
    
    if(dp[start][end][target]!=-1) return dp[start][end][target];
    
    if(start==end){
        if(target==1)
            return dp[start][end][target] = (exp[start]=='T'); // return 1 if we met the target else 0
        else
            return dp[start][end][target] = (exp[start]=='F');
    }
    
    int curcount=0;
    for(int k=start+1;k<=end-1;k+=2){
        // left true
        if(dp[start][k-1][1]==-1)
            dp[start][k-1][1] = solve(exp, start, k-1, 1);
        // left false
        if(dp[start][k-1][0]==-1)
            dp[start][k-1][0] = solve(exp, start, k-1, 0);
        // right true
        if(dp[k+1][end][1]==-1)
            dp[k+1][end][1] = solve(exp, k+1, end, 1);
        // right false
        if(dp[k+1][end][0]==-1)
            dp[k+1][end][0] = solve(exp, k+1, end, 0);
        
        if(exp[k]=='&')
            if(target==1)
                curcount+=(dp[start][k-1][1]*dp[k+1][end][1])%mod;
            else
                curcount+=((dp[start][k-1][1]*dp[k+1][end][0])%mod)+((dp[start][k-1][0]*dp[k+1][end][1])%mod)+(dp[start][k-1][0]*dp[k+1][end][0])%mod;
        if(exp[k]=='|')
            if(target==1)
                curcount+=((dp[start][k-1][1]*dp[k+1][end][1])%mod)+((dp[start][k-1][1]*dp[k+1][end][0])%mod)+((dp[start][k-1][0]*dp[k+1][end][1])%mod);
            else
                curcount+=(dp[start][k-1][0]*dp[k+1][end][0])%mod;
        if(exp[k]=='^')
            if(target==1)
                curcount+=((dp[start][k-1][1]*dp[k+1][end][0])%mod)+((dp[start][k-1][0]*dp[k+1][end][1])%mod);
            else
                curcount+=(dp[start][k-1][0]*dp[k+1][end][0])%mod + (dp[start][k-1][1]*dp[k+1][end][1])%mod;
    }
    return dp[start][end][target]=curcount%mod;
}

int Solution::cnttrue(string A) {
    int n=A.size();
     for(int i=0; i<151; i++){
        for(int j=0; j<151; j++){
            for(int k=0; k<2; k++){
                dp[i][j][k]=-1;
            }
        }
    }
    return solve(A, 0, n-1, 1);
}

// TC: O(n^3)
// SC: O(n^3) for dp array