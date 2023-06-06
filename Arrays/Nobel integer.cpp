// https://www.interviewbit.com/problems/noble-integer/

// Approach:
// count the frequency of each element in the array and store it in an ordered map
// iterate over the map and subtract the frequency of the current element from the total count
// if the current element is equal to the count, return 1
// if no such element is found, return -1

int solve(vector<int> &A)
{
    map<int, int> hash;
    for (int x : A)
        ++hash[x];
    map<int, int>::iterator it;
    int countSum = 0;
    for (auto x : hash)
        countSum += x.second;

    it = hash.begin();
    for (; it != hash.end(); ++it)
    {
        countSum -= it->second;
        if (it->first == countSum)
            return 1;
    }
    return -1;
}

// TC: O(nlogn)
// SC: O(n)