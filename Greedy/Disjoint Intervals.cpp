// https://www.interviewbit.com/problems/disjoint-intervals/

// Approach:
// Sort the intervals based on the end time.
// Now, if the next interval's start time is greater than the previous interval's end time, then we can say that the intervals are disjoint.
// else keep moving forward to next interval.

bool compare(vector<int> &a, vector<int>  &b){
    return a[1]<b[1];
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), compare);
    
    int res=1;
    int prev=A[0][1];
    int n=A.size();
    
    for(int i=1;i<n;++i){
        if(prev < A[i][0])
        {
            ++res;
            prev=A[i][1];
        }
    }
    
    return res;
}

// TC: O(nlogn)
// SC: O(1)