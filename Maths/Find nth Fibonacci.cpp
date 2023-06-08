// Optimal approach: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/ (Method 4)

int solve(int A)
{
    // TLE on hard case
    int a=1;
    int b=1;
    int mod=1e9+7;

    if(A==1 || A==2) return 1;
    A-=2;

    while(A--)
    {
        int temp=a;
        a=b;
        b=b+temp;
    }
    return b%mod;
}

// TC : O(n)
// SC : O(1)