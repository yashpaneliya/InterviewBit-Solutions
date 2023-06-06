// https://www.interviewbit.com/problems/largest-number/

// Approach:
// convert int array to string array
// create a compare function which will compare two strings s1 and s2
//      ex. 2223 and 224 => X=2223224 and Y=2242223
//      if X>Y, return true // this will place 224 before 2223
//      else return false
// sort the string array using the compare function
// if the first element of the sorted array is 0, return 0
// else return the concated sorted array

bool compare(string &s1, string &s2)
{
    string s1s2 = s1 + s2;
    string s2s1 = s2 + s1;
    return s1s2 > s2s1;
}

string largestNumber(const vector<int> &A)
{
    vector<string> arr;

    for (int x : A)
        arr.push_back(to_string(x));

    sort(arr.begin(), arr.end(), compare);
    if (arr[0] == "0")
        return "0";
    string res = "";
    for (string s : arr)
        res += s;
    return res;
}

// TC: O(nlogn)
// SC: O(n*strlen(max(A)))