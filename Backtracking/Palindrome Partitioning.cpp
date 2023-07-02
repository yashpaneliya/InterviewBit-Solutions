// https://www.interviewbit.com/problems/palindrome-partitioning/

// Approach:
// Generate all substrings and check if it is palindrome if yes then move forward to partition next remaining string
// If we reach the end of string, then add current vector to result

vector<vector<string>> res;

bool ispalindrome(string s){
    int n=s.size();
    for(int i=0;i<n;++i){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}

void util(string &s, int index, vector<string> curvec){
    int n=s.size();
    
    if(index==n)
    {
        res.push_back(curvec);
        return;
    }
    
    string str;
    for(int i=index;i<n;++i)
    {
        str+=s[i]; // make a string till it is palindrome
        if(ispalindrome(str)){
            curvec.push_back(str); // push it to current vector
            util(s, i+1, curvec);  // start partitioning from next character bcoz we have already considered string till index to i
            curvec.pop_back();     // pop it out to generate longer string then previous one with same initial characters
        }  
    }
}

vector<vector<string> > Solution::partition(string A) {
    res.resize(0);
    vector<string> curvec;
    util(A, 0, curvec);
    return res;
}

// TC: 
// SC: 