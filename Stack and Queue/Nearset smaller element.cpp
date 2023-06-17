// https://www.interviewbit.com/problems/nearest-smaller-element/

// Approach:
// Use stack to store elements
// For each element, pop elements from stack till top element is greater than current element
// If stack is empty, then there is no smaller element on left side
// Else, top element of stack is smaller element on left side
// Push current element in stack

vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n, -1);

    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && A[i] <= st.top())
        {
            st.pop();
        }
        res[i] = st.top();
        st.push(A[i]);
    }
    return res;
}

// TC: O(n)
// SC: O(n)