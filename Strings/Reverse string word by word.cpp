// https://www.interviewbit.com/problems/reverse-the-string/

// Approach:
// trim the string
// iterate till a white space comes and append the word to the result string in reverse order
// reset the temp string and continue the process

string Solution::solve(string A) {
    string temp = "";
    int i = 0, j=A.size()-1;
    
    // trim the string
    while(A[i++]==' ');
        
    while(A[j--]==' ');
    
    --i;
    ++j;

    string res="";
    for(;i<=j;++i)
    {
        if(A[i]==' ')
        {
            if(temp.size()!=0)
            {
                if(res.size()==0)
                    res = temp;
                else
                    res = temp + " " + res;
                temp="";
            }        
        }
        else{
            temp+=A[i];
        }
    }
    
    // last word remaining to append
    if(temp.size()!=0 && res.size()!=0)
        res = temp + " " + res;
    // if only onw word is there in input without any spaces
    if(temp.size()!=0 && res.size()==0)
        return temp;
    return res;
}

// TC: O(n)
// SC: O(n)