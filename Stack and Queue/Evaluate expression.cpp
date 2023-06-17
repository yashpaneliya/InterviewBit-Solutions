// https://www.interviewbit.com/problems/evaluate-expression/

// Approach:
// Use stack to store operands
// For each operator, pop two operands from stack and perform operation
// Push result back in stack

int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    int n=A.size();
    int a,b;
    for(int i=0;i<n;++i)
    {
        if(A[i]=="+"){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a+b);
        } else if(A[i]=="-"){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(b-a);
        } else if(A[i]=="*"){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a*b);
        } else if(A[i]=="/"){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(b/a);
        } else{
            int num=stoi(A[i]);
            st.push(num);
        }        
    }
    return st.top();
}

// TC: O(n)
// SC: O(n)