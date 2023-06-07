// // https://www.interviewbit.com/problems/palindrome-integer/

// Approach 1: 
// Convert to string and check for palindrome

// Approach 2:
// Find the number of digits in the number
// Compare the first and last digits, second and second last digits and so on
// If any of the pairs do not match, return 0

int isPalindrome(int A) {
    if(A<0) return 0;

    // 1.    
    // string s1=to_string(A);
    // string s2=string(s1.rbegin(), s1.rend());
    // for(int i=0;i<s1.size();++i)
    //     if(s1[i]!=s2[i])
    //         return 0;
    // return 1;

    // 2.
    int digLen=0;
    int temp=A;
    while(temp!=0)
    {
        ++digLen;
        temp=temp/10;
    }
    
    for(int i=0;i<digLen;++i)
    {
        int d1=(A/(int)pow(10,i))%10;
        int d2=(A/(int)pow(10,digLen-1-i))%10;
        if(d1!=d2)
            return 0;
    }
    return 1;
}

// TC: O(n)
// SC: O(n) and O(1)