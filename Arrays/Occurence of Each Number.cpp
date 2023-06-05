// Problem link: https://www.interviewbit.com/problems/occurence-of-each-number/

// Approach

// 1.
// Count the frequency using ordered map
// store frequencies in an vector and return it

// 2.
// Sort the array
// keep updating count till adjacent element mismatch
// push the count to vector and reset the count

vector<int> findOccurences(vector<int> &A)
{
    // 1.
    map<int, int> map;
    for (int x : A)
        ++map[x];
    vector<int> res;
    for (auto x : map)
        res.push_back(x.second);
    return res;

    // 2.
    // sort(A.begin(),A.end());
    // int cnt=1;
    // int n=A.size();
    // vector<int> res;
    // for(int i=1;i<n;++i)
    // {
    //     if(A[i]==A[i-1])
    //         ++cnt;
    //     else{
    //         res.push_back(cnt);
    //         cnt=1;
    //     }
    // }
    // res.push_back(cnt);
    // return res;
}

// TC: O(n)
// SC: O(n)