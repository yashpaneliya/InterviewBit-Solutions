// https://www.interviewbit.com/problems/tiling-with-dominoes/

// Approach 1:
// An = No. of ways to completely fill a 3 x n board. (We need to find this)
// Bn = No. of ways to fill a 3 x n board with top corner in last column not filled.
// Cn = No. of ways to fill a 3 x n board with bottom corner in last column not filled.
// Bn = Cn because of symmetry.
// For odd number of columns, it's not possible for us to fill the board completely.
// For even number of columns, we can fill the board completely.

int Solution::solve(int A) {
    if(A%2 != 0) return 0;
    
    if(A==2) return 3;
    
    int a[A+1];
    int b[A+1];
    
    int mod = 1e9+7;
    
    a[0] = 1;
    a[1] = 0;
    b[0] = 0;
    b[1] = 1;
    
    for(int i=2;i<=A;++i){
        if(i%2==0){
            a[i] = (a[i-2] + (b[i-1]*1 + b[i-1]*1)%mod)%mod; 
            b[i] = 0;
        } else{
            a[i] = 0;
            b[i] = (b[i-2] + a[i-1]*1)%mod;
        }
    }
    return a[A]%mod;
}

// TC: O(n)
// SC: O(n)