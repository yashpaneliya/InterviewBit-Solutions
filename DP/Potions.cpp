// https://www.interviewbit.com/problems/potions/

// Approach 1:
// dp[i][j] = min smoke produced by mixing potions from ith to jth bottle
// Question follows the same pattern as Matrix chain multiplication

int dp[101][101];

int rangesum(vector<int> &A, int i, int j){
    int sum=0;
    for(int k=i;k<=j;++k)
        sum = (sum + A[k]) % 100;
    return sum;
}

int mcm(vector<int> &A, int i, int j){
    if(i>=j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int minsmoke = INT_MAX;
    for(int k=i;k<j;++k){
        int temp = mcm(A,i,k) + mcm(A,k+1,j) + rangesum(A,i,k)*rangesum(A,k+1,j);
        minsmoke = min(minsmoke, temp);
    }
    return dp[i][j] = minsmoke;
}

int Solution::minSmoke(vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    int n=A.size();
    return mcm(A,0,n-1);
}

// TC: O(n^3)
// SC: O(n^2)