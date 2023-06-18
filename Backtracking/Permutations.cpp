// https://www.interviewbit.com/problems/permutations/

// Approach:
// Use backtracking to find all combinations
// For each element, add it to current combination and recursively call for next index
// Once we reach the end of the array, add the current combination to result


vector<vector<int>> res;

void util(vector<int>& arr, int index, vector<int> curvec, int n, vector<bool> visited){    
    if(curvec.size()==n){
        res.push_back(curvec);
        return;
    }
    
    for(int i=0;i<n;++i){
        if(i!=index && visited[i]==false)
        {
            visited[i]=true;
            curvec.push_back(arr[i]);
            util(arr, i, curvec, n, visited);
            curvec.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    res.resize(0);
    int n=A.size();
    vector<bool> visited(n,false);
    vector<int> curvec;
    for(int i=0;i<n;++i)
    {
        visited[i]=true;
        curvec.push_back(A[i]);
        util(A, i, curvec, n, visited);
        curvec.pop_back();
        visited[i] = false;
    }
    return res;
}

// TC: O(n!)
// SC: O(n)