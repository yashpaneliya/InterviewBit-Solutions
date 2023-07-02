// https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

// Approach:
// dp[i] = number of BST possible for i nodes
// Make jth element as root and then find number of BST possible for left and right subtree
// Ex. For 0 to i elements, find possible BSTs for 0 to j-1 and j+1 to i for each j
// multiply them and add to sum

int Solution::numTrees(int A) {
    int dp[A+1];
    
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
     
    for(int i=3;i<=A;++i){
        int sum=0;
        for(int j=1;j<=i;++j){
            int leftcount = dp[j-1];
            int rightcount = dp[i-j];
            sum+=(leftcount*rightcount);
        }
        dp[i]=sum;
    }
    return dp[A];
}

// TC: O(n^2)
// SC: O(n)