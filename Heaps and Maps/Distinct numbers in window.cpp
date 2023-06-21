// https://www.interviewbit.com/problems/distinct-numbers-in-window/

// Approach:
// Use a hash map to store the frequency of each element in the first window
// Push the size of the hash map into the result vector
// For each subsequent window, remove the first element of the previous window and add the next element
// If the frequency of the removed element is 0, remove it from the hash map
// Push the size of the hash map into the result vector

vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> hash;
    
    for(int i=0;i<B;++i)
        ++hash[A[i]];  
        
    vector<int> res;
    res.push_back(hash.size());
    for(int j=B;j<A.size();++j){
        --hash[A[j-B]];
        ++hash[A[j]];
        
        if(hash[A[j-B]]==0)
            hash.erase(A[j-B]);
        
        res.push_back(hash.size());
    }
    return res;
}

// TC: O(NlogB)
// SC: O(B)