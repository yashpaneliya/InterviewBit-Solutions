// https://www.interviewbit.com/problems/highest-product/

// Approach:
// Find 3 highest elements and 2 lowest elements.
// return max of (max1*max2*max3, min1*min2*max1)
// Because if we have more than 1 negative number then product of 2 negative numbers (min1, min2) will be positive.
// So, we need to consider that case also.

int Solution::maxp3(vector<int> &A) {
    int n=A.size();
    
    int max1=INT_MIN;
    int max2=INT_MIN;
    int max3=INT_MIN;
    
    int min1=INT_MAX;
    int min2=INT_MAX;
    
    for(int i=0;i<n;++i){
        if(A[i]>max1){
            max3=max2;
            max2=max1;
            max1=A[i];
        } else if(A[i]>max2){
            max3=max2;
            max2=A[i];
        } else if(A[i]>max3){
            max3=A[i];
        }
        
        if(A[i]<min1){
            min2=min1;
            min1=A[i];
        } else if(A[i]<min2){
            min2=A[i];
        }
    }
    
    return max(max1*max2*max3, min1*min2*max1);
}

// TC: O(n)
// SC: O(1)