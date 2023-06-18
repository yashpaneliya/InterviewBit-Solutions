// https://www.interviewbit.com/problems/anagrams/

// Approach:
// Sort each string and store its location in a hash map
// return each list of locations as a vector

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> hash;
    string str;
    
    for(int i=0;i<A.size();++i){
        str=A[i];
        sort(str.begin(),str.end());
        hash[str].push_back(i+1);
    }
    
    vector<vector<int>> res;
    for(auto ele:hash){
        res.push_back(ele.second);
    }
    
    return res;
}

// TC: O(n*mlogm) where n is number of strings and m is length of each string
// SC: O(n*m)

// Another approach based on squared sum of characters
/*
int charsum(string A){
    int i=0;
    int sum=0;
    while(i<A.size()){
        sum+=A[i]*A[i];
        i++;
    }
    return sum;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<int,vector<int>> mp;
    vector<vector<int>> ans;
    vector<int> store;
    for(int i=0; i<A.size(); i++){
        store.push_back(charsum(A[i]));
    }
    for(int i=0; i<store.size(); i++){
        mp[store[i]].push_back(i+1);
    }
    for(auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
}
*/