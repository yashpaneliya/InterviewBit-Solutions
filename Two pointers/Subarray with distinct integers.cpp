// https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

// Approach:
// At each step, it updates the frequency of the current element and checks if the number of different integers (frequency.size()) exceeds B. If it does, the algorithm moves the left pointer to the right until the subarray has only B different integers.
// Once we have a subarray with exactly B different integers, we count the number of subarrays that can be formed by moving the left pointer to the right while maintaining B different integers. This count is stored in the count variable.
// Finally, if the number of different integers in the subarray is exactly B, we add count + 1 to the result since we can form subarrays of length 1 to count + 1 with exactly B different integers.

int Solution::solve(vector<int> &A, int B)
{
    // int subcount=0;
    // int n=A.size();

    // int i=0,j=1;
    // unordered_map<int,int> hash;
    // int distcount=1;
    // hash[A[0]]=1;

    // while(i<n && j<n)
    // {
    //     if(distcount==B)
    //     {
    //         ++subcount;
    //         --hash[i];
    //         if(hash[i]==0)
    //         {
    //             --distcount;
    //             ++i;
    //         }
    //     }
    //     else if(distcount<B)
    //     {
    //         if(hash[j]==0)
    //             ++distcount;
    //         ++hash[j];
    //         ++j;
    //     } else{
    //         --hash[i];
    //         if(hash[i]==0)
    //             --distcount;
    //         ++i;
    //     }
    // }
    // return subcount;

    int n = A.size();
    unordered_map<int, int> frequency;
    int left = 0, right = 0;
    int count = 0, result = 0;

    while (right < n)
    {
        frequency[A[right]]++;
        if (frequency.size() > B)
        {
            while (frequency.size() > B)
            {
                frequency[A[left]]--;
                if (frequency[A[left]] == 0)
                    frequency.erase(A[left]);
                left++;
            }
            count = 0;
        }
        while (frequency[A[left]] > 1)
        {
            frequency[A[left]]--;
            left++;
            count++;
        }
        if (frequency.size() == B)
            result += count + 1;
        right++;
    }

    return result;
}

// TC: O(n)
// SC: O(n)