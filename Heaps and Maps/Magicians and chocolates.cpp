// https://www.interviewbit.com/problems/magician-and-chocolates/discussion/p/easy-simple-code-in-java/411286/1033/

// Approach:
// Use a max heap to store the number of chocolates in each bag
// Pop the max element and add it to the total count
// Push the floor of the popped element/2 back into the heap

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> maxheap;
    for(int x:B)
        maxheap.push(x);
    int count=0;
    int mod=1e9+7;
    while(A--){
        int bi = maxheap.top();
        count = (count + (bi%mod)) % mod;
        maxheap.pop();
        maxheap.push(floor(bi/2));
    }
    return count%mod;
}

// TC: O(nlogn)
// SC: O(n)