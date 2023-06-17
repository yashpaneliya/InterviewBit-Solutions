// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

// Approach:
// Use a queue to store non repeating characters
// Use a hash map to store frequency of each character
// For each character, if it is not present in hash map, push it in queue and update hash map
// If it is present in hash map, increment its frequency and pop all characters from queue whose frequency is greater than 1
// If queue is empty, push '#' in result string else push front of queue in result string

string Solution::solve(string A)
{
    unordered_map<char, int> hash;
    queue<char> q;

    int n = A.size();
    q.push(A[0]);
    hash[A[0]] = 1;

    string res = "";
    res += A[0];

    for (int i = 1; i < n; ++i)
    {
        ++hash[A[i]];
        if (hash[A[i]] == 1)
            q.push(A[i]);
        while (!q.empty() && hash[q.front()] > 1)
        {
            q.pop();
        }

        if (q.empty())
            res += "#";
        else
            res += q.front();
    }
    return res;
}

// TC: O(n)
// SC: O(n)