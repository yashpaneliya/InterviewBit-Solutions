// https://www.interviewbit.com/problems/min-stack/

// Approach:
// Use two stacks, one for storing elements and other for storing cumulative minimum element
// For each push operation, push element in min stack only if it is less than current minimum element
// For each pop operation, pop element from both stacks

stack<int> mintracker;
stack<int> st;

MinStack::MinStack()
{
    while (!st.empty())
    {
        st.pop();
        mintracker.pop();
    }
}

void MinStack::push(int x)
{
    if (mintracker.empty())
    {
        mintracker.push(x);
    }
    else if (x < mintracker.top())
    {
        mintracker.push(x);
    }
    else
    {
        mintracker.push(mintracker.top());
    }
    st.push(x);
}

void MinStack::pop()
{
    if (st.empty())
        return;
    st.pop();
    mintracker.pop();
}

int MinStack::top()
{
    if (st.empty())
        return -1;
    return st.top();
}

int MinStack::getMin()
{
    if (st.empty())
        return -1;
    return mintracker.top();
}

// TC: O(1)
// SC: O(n)