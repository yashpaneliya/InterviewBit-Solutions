// https://www.interviewbit.com/problems/minimum-parantheses/

// Approach:
// Use stack
// if '(' push to stack
// if ')' pop from stack
// if stack is empty and ')' is encountered, then increment count
// return count + stack.size()

int Solution::solve(string A)
{
    stack<char> st;
    int count = 0;
    for (char c : A)
    {
        if (c == '(')
            st.push('(');
        else
        {
            if (st.empty())
                count++;
            else
                st.pop();
        }
    }
    count += st.size();
    return count;
}

// TC: O(n)
// SC: O(n)