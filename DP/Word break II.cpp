// https://www.interviewbit.com/problems/word-break-ii/hints/

// Approach:
// 1. Recursively check for each possible combination to form the sentence by breaking the original string whenever a word from dictionary is found
// 2. Store all the possible sentences in a vector and return it

vector<string> res;

string findString(string A, vector<string> &B, int i, int j){
    string temp = A.substr(i,(j-i+1));
    for(string s:B)
        if(temp==s)
            return temp;
    return "";
}

string vec2str(vector<string> vs){
    string temp="";
    temp+=vs[0];
    for(int i=1;i<vs.size();++i){
        temp = temp +" "+vs[i];
    }
    return temp;
}

void util(string A,vector<string> &B, int i, vector<string> curres){
    if(i>=A.size()){
        res.push_back(vec2str(curres));
        return;
    }
    
    for(int j=i;j<A.size();++j){
        string temp=findString(A,B,i,j);
        if(temp!=""){
            curres.push_back(temp);
            util(A,B,j+1,curres);
            curres.pop_back();
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    res.clear();
    int n = A.size();
    vector<string> curres;
    util(A,B,0,curres);
    return res;
}

// TC: O(2^n)
// SC: O(n*l), l=length of string