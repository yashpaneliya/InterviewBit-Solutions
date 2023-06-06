// https://www.interviewbit.com/problems/find-duplicate-in-array/

// Approach1:
// Using hash table
// TC: O(n)
// SC: O(n)

// Approach2:
// Slow and fast pointer approach
// initialize slow to A[0] and fast to A[A[0]]
// slow = A[slow] and fast = A[A[fast]] -> we will reach to the point where slow and fast are equal
// initialize slow to 0 and search where slow is equal to fast
// slow = A[slow] and fast = A[fast]
// return slow
// TC: O(n)
// SC: O(1)

int repeatedNumber(const vector<int> &A)
{
    // unordered_map<int,bool> hash;
    // for(int x:A)
    // {
    //     if(hash[x])
    //         return x;
    //     else
    //         hash[x]=true;
    // }
    // return -1;

    int slow = A[0];
    int fast = A[A[0]];

    // finding the number which is repeated
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }

    slow = 0;

    while (slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }

    return slow;
}
