// https://www.interviewbit.com/problems/maximum-sum-combinations/discussion/p/very-easy-min-heap-c-solution/417779/1867/

// Approach:
// Sort both arrays in descending order
// push the pairwise sum of first C elements of both arrays into a min heap
// For each pair if sum of them greater than the top of min heap, pop the top and push the sum
// Maintain the size of heap as C

bool comp(int& a, int& b){
    return a>b;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> sums;
    sort(A.begin(),A.end(),comp);
    sort(B.begin(),B.end(),comp);
    
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    int k=0;
    
    while(k<A.size()){
        minheap.push(A[k]+B[k]);
        if(minheap.size()>C)
        {
            minheap.pop();
            break;
        }
        ++k;
    }
    
    for(int i=0;i<A.size();++i){
        for(int j=0;j<B.size();++j){
            if(i!=j){
                if(A[i]+B[j]>minheap.top())
                {   
                    minheap.pop(); 
                    minheap.push(A[i]+B[j]);
                } else{
                    break;
                }
                if(minheap.size()>C){
                    minheap.pop();
                }
            } 
        }
    }
    
    sums.resize(C,0);
    while(!minheap.empty()){
        sums[C-1]=minheap.top();
        minheap.pop();
        --C;
    }
    
    return sums;
}

// TC: O(n^2logC)
// SC: O(C)