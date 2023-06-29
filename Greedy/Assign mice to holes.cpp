// https://www.interviewbit.com/problems/assign-mice-to-holes/hints/

// Approach:
// Sort both the arrays.
// find the max time by a mouse to reach a hole.

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int res=INT_MIN;
    for(int i=0;i<A.size();++i){
        res = max(res, abs(A[i]-B[i]));
    }
    return res;
}

// TC: O(nlogn)
// SC: O(1)