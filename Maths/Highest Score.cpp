// https://www.interviewbit.com/problems/highest-score/

// Approach:
// Store the sum and frequency each string in a hash map
// Find the average of each string and store the maximum average

int highestScore(vector<vector<string> > &A) {
    unordered_map<string, pair<int,int>> hash;
    for(auto st:A)
    {
        ++hash[st[0]].first;
        hash[st[0]].second+=stoi(st[1]);
    }
    
    int max=INT_MIN;
    for(auto st:hash)
    {
        int avg = floor(st.second.second/st.second.first);
        if(avg>max)
            max=avg;
    }
    return max;
}

// TC: O(n)
// SC: O(n)