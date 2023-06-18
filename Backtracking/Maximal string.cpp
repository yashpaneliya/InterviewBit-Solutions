// https://www.interviewbit.com/problems/maximal-string/

// Approach:
// Use backtracking to find all combinations
// For each element, 
//       do not swap current index element and move forward
//   &   swap it with all elements after it and recursively call for next index
// If number of swaps is equal to B or index is equal to string size, then check if current string is greater than result string
// If yes, then update result string

string res;

void util(string s, int swaps, int B, int index){
    int n=s.size();
    if(swaps==B || index==n){
        if(res<s)
            res=s;
        return;
    }
    
    // do not swap current index element and move forward
    util(s, swaps, B, index+1);
    
    // swap with each element after index
    // Why starting with index? 
    // ==> Because from 0 to index-1, all possible swaps are already considered by previous function calls
    for(int i=index;i<n;++i){
        if(s[i]>s[index]){ // just to exclude unneccessary swaps which construct lex. smaller strings
            swap(s[i],s[index]);
            util(s,swaps+1,B,index+1);
            swap(s[i],s[index]);   
        }
    }
}

string Solution::solve(string A, int B) {
    if(B==0) return A;
    res=A;
    util(A,0,B,0);
    return res;
}

// TC: O(n!)
// SC: O(n)