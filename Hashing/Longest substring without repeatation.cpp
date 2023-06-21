// https://www.interviewbit.com/problems/longest-substring-without-repeat/

// Approach:
// Use a hash map to store the status of occurance of each character in the current window
// If a character is repeated, move the left pointer till the matched character
// Move the left pointer to the new starting point of the window
// Increment the right pointer
// Update the max length of the window

int Solution::lengthOfLongestSubstring(string A) {
    int i=0,j=0;
    int n = A.size();
    unordered_map<char,int> hash;
    int maxlen=1;
    
    while(i<=j && j<n){
        if(hash[A[j]]>0){ // if character is repeated
            if(j-i > maxlen){
                maxlen=j-i;
            }
            // move left pointer till matched character
            while(A[i]!=A[j])
            {
                hash[A[i]]=0;
                ++i;
            }
            // move left pointer to new starting point of window(substring)
            ++i;
            // increment right pointer
            hash[A[j]]=1;
            ++j;
        } else{
            hash[A[j]]=1;
            ++j;
        }
    }
    if(j-i > maxlen){
        maxlen=j-i;
    }
    return maxlen;
}

// TC: O(N)
// SC: O(N)