// https://www.interviewbit.com/problems/palindrome-partitioning-ii/discussion/p/standard-dp-c/423335/407/

// int mincount;

bool ispalindrome(string s){
    int n=s.size();
    for(int i=0;i<n/2;++i)
        if(s[i]!=s[n-i-1])
            return false;
    return true;
}
// recursive approach
// void util(string A, int i, int count){
//     if(i>=A.size()){
//         mincount = min(mincount,count-1);
//         return;
//     }
//     string temp;
//     for(int j=i;j<A.size();++j){
//         temp+=A[j];
//         if(ispalindrome(temp)){
//             util(A,j+1, count+1);
//         }
//     }
// }

// dp[i] = minimum possible palindrome substrings till ith index

int Solution::minCut(string A) {
    // mincount=INT_MAX;
    if(ispalindrome(A)) return 0;
    int n=A.size();
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    // util(A,0,0);
    for(int i=0;i<n;++i){
        string temp="";
        for(int j=i+1;j<=n;++j){
            temp+=A[j-1];
            if(ispalindrome(temp))
                dp[j]=min(dp[j], dp[i]+1); // same as doing count+1 in recursive approach
        }
    }
    return dp[n]-1;
}

// can also be done using MCM pattern

// TC: O(n^2*l) , l=length of string
// SC: O(n)