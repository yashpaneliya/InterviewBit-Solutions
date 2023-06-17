// https://www.interviewbit.com/problems/combination-sum/

// Approach:
// Sort the array
// Use backtracking to find all combinations
// If current sum is greater than required sum, then return
// If current sum is equal to required sum, then add current combination to result
// Else, for each element, add it to current combination and recursively call for next index

vector<vector<int>> res;

void util(vector<int>& arr, vector<int> curvec, int cursum, int sum, int index){
    if(cursum>sum)
        return;
    
    if(cursum==sum){
        res.push_back(curvec);
        return;
    }
    
    for(int i=index;i<arr.size();++i){
        curvec.push_back(arr[i]);
        util(arr, curvec, cursum+arr[i], sum, i);
        curvec.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    res.resize(0);
    
    sort(A.begin(), A.end());
    vector<int> cur;
    util(A,cur,0,B,0);
    
    map<vector<int>,int> mp;
    for(int i=0;i<res.size();i++){
        mp[res[i]]++;
    }
    
    res.resize(0);
    for(auto it:mp){
        res.push_back(it.first);
    }
    return res;
}

// TC: O(2^n)
// SC: O(n)