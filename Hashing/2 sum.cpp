// https://www.interviewbit.com/problems/2-sum/

// Approach:
// Use a hash map to store the index of each element
// For each element, check if B-element is present in the hash map
// If yes, return the indices

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> hash;
    
    for(int i=0;i<A.size();++i){
        if(hash.find(B-A[i]) != hash.end()){
            vector<int> res;
            res.push_back(hash[B-A[i]]);
            res.push_back(i+1);
            return res;
        } else{
            if(hash.find(A[i])==hash.end())
                hash[A[i]] = i+1;
        }
    }
    return {};
}

// TC: O(N)
// SC: O(N)