// https://www.interviewbit.com/problems/rain-water-trapped/

// Approach:
// For each element, find tallest bar on left and right side
// The water trapped at current location is difference between minimum of height of tallest bars on both side from current location and height of currentlocation
// Add water trapped at each location to get total water trapped
// maintain two arrays, one for storing tallest bar on left side and other for storing tallest bar on right side

int Solution::trap(const vector<int> &A) {
    int n= A.size();
    if(n<=2)
        return 0;
        
    vector<int> leftmax(n,0);
    leftmax[0]=A[0];
    vector<int> rightmax(n,0);
    rightmax[n-1]=A[n-1];
    
    // we want to find tallest bar from current location on both left and right side
    for(int i=1;i<n;++i)
    {
        leftmax[i] = max(A[i], leftmax[i-1]);
        rightmax[n-i-1] = max(A[n-i-1], rightmax[n-i]);
    }
    
    int water = 0;
    // the answer is difference between minimum of height of tallest bars on both side from current location and height of currentlocation
    for(int i=0;i<n;++i){
        water+=min(leftmax[i], rightmax[i]) - A[i];
    }
    return water;
}


// TC: O(n)
// SC: O(n)