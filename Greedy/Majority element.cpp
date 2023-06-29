// https://www.interviewbit.com/problems/majority-element/hints/

// Approach:
// count the frequency of each element in a hash table.
// return the element with frequency > floor(n/2)

int Solution::majorityElement(const vector<int> &A) {
    unordered_map<int, int> hash;
    int n=A.size();
    
    for(int x:A){
        ++hash[x];
        if(hash[x]>floor(n/2))
            return x;
    }
}

// TC: O(n)
// SC: O(n)