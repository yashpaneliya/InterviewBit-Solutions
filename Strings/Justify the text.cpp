// https://www.interviewbit.com/problems/justified-text/

// Approach:
// Greedy + Brute force
// Check all corner and general cases for extra spaces between words and space at the end for last word of the input

string justify(vector<string> &str, int maxlen, int curlen, int start, int end)
{
    string res = "";
    // if only one word is accomodated in the line
    if (start == end)
    {
        int remainingSpaces = maxlen - str[end].size();
        res += str[end];
        while (remainingSpaces--)
            res += " ";
        return res;
    }

    int gaps = end - start;
    // couting remainingSpaces
    // total len - current occupied len - single space between current words
    int remainingSpaces = maxlen - curlen - gaps;
    int extraspaces = remainingSpaces % (gaps);
    int addspace = remainingSpaces / (gaps);

    for (int i = start; i <= end; ++i)
    {
        res += str[i];
        if (i != end)
        {
            for (int j = 0; j < addspace; ++j)
                res += " ";
            if (extraspaces)
            {
                res += " ";
                --extraspaces;
            }
        }
    }

    return res;
}

vector<string> Solution::fullJustify(vector<string> &A, int B)
{
    vector<string> res;
    int wordCount = A.size();
    int i = 0;
    int curstrlen = 0;
    string temp;
    // vector<string> res;
    int nextstart = 0;
    while (i < wordCount)
    {
        curstrlen += A[i].size() + 1;
        temp += A[i] + " ";
        if (curstrlen - 1 == B)
        {
            temp.pop_back();
            res.push_back(temp);
            curstrlen = 0;
            temp = "";
            nextstart = i + 1;
        }
        else if (curstrlen - 1 > B)
        {
            temp = justify(A, B, curstrlen - A[i].size() - 2, nextstart, i - 1);
            res.push_back(temp);
            temp = "";
            --i;
            curstrlen = 0;
            nextstart = i + 1;
        }
        else
        {
            if (i == wordCount - 1)
            {
                while (curstrlen < B)
                {
                    temp += " ";
                    ++curstrlen;
                }
                res.push_back(temp);
            }
        }
        ++i;
    }

    return res;
}

// TC: O(n2)
// SC: O(n)

// string justify(vector<string> &str, int maxlen, int curlen)
// {
//     string res = "";
//     int words = str.size();
//     int remainingSpaces = maxlen - curlen - (words - 1);

//     if (words == 1)
//     {
//         res += str[0];
//         while (remainingSpaces--)
//             res += " ";
//         return res;
//     }
//     if (remainingSpaces % (words - 1) == 0)
//     {
//         int spaces = remainingSpaces / (words - 1);
//         for (int i = 0; i < words - 1; ++i)
//         {
//             res += str[i];
//             for (int j = 0; j < spaces; ++j)
//                 res += " ";
//         }
//         res += str[words - 1];
//     }
//     else
//     {
//         int extraspaces = remainingSpaces % (words - 1);
//         int spaces = remainingSpaces / (words - 1);
//         for (int i = 0; i < words - 1; ++i)
//         {
//             res += str[i];
//             for (int j = 0; j < spaces; ++j)
//                 res += " ";
//             if (extraspaces--)
//                 res += " ";
//         }
//     }
//     return res;
// }

// vector<string> Solution::fullJustify(vector<string> &A, int B)
// {
//     vector<string> res;
//     int wordCount = A.size();
//     int i = 0;

//     // while(i<wordCount)
//     // {
//     //     vector<string> temp;
//     //     int len=B;
//     //     int count=0;
//     //     int curlen=0;
//     //     while(true)
//     //     {
//     //         if(A[i].size() + 1 <= len)
//     //         {
//     //             temp.push_back(A[i]);
//     //             ++i;
//     //             curlen+=A[i].size();
//     //             len-=(A[i].size()+1);
//     //         } else
//     //             break;
//     //     }
//     //     string justStr = justify(temp, B, curlen);
//     //     res.push_back(justStr);
//     // }
//     int curstrlen = 0;
//     vector<string> temp;
//     // vector<string> res;
//     while (i < wordCount)
//     {
//         curstrlen += A[i].size() + 1;
//         temp.push_back(A[i]);
//         if (curstrlen - 1 == B)
//         {
//             string curstr;
//             for (int j = 0; j < temp.size() - 1; ++j)
//                 curstr += temp[j] + " ";
//             curstr += A[i];
//             res.push_back(curstr);
//             curstrlen = 0;
//             temp.resize(0);
//         }
//         else if (curstrlen - 1 > B)
//         {
//             string curstr = justify(temp, B, curstrlen - A[i].size() - 1);
//             temp.resize(0);
//             res.push_back(curstr);
//             --i;
//             curstrlen = 0;
//         }
//         else
//         {
//             if (i == wordCount - 1)
//             {
//                 string curstr = "";
//                 for (int j = 0; j < temp.size() - 1; ++j)
//                     curstr += temp[j] + " ";
//                 curstr += A[i];
//                 while (curstrlen < B)
//                     curstr += " ";
//                 res.push_back(curstr);
//             }
//         }
//         ++i;
//     }

//     return res;
// }