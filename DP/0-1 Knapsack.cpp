// https://www.interviewbit.com/problems/0-1-knapsack/

// Approach:
// Maintain a dp array of size (N+1)*(Capacity+1)
// dp[i][j] = max value of knapsack with i items and j capacity
// Top down approach
// if weight of current item is greater than capacity then move to next item
// else take max of either of item included or not included

int knapsack(vector<int>& value, vector<int>& weights, int maxcap, vector<vector<int>>& dp, int i){
    if(i<0) return 0;
    
    int weight = weights[i];
    
    if(dp[i][maxcap]!=-1)
        return dp[i][maxcap];
    
    if(weight > maxcap){
        return dp[i][maxcap] = knapsack(value, weights, maxcap, dp, i-1);
    } else{
        dp[i][maxcap] = max(knapsack(value, weights, maxcap-weight, dp, i-1) + value[i], knapsack(value, weights, maxcap, dp, i-1));
        return dp[i][maxcap];
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    // dp array of size (N+1)*(Capacity+1)
    vector<vector<int>> dp(n+1, vector<int> (C+1,-1));    
    
    return knapsack(A,B,C,dp,n-1);
}

// TC: O(n*Capacity)
// SC: O(n*Capacity) for dp array