// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

// Approach 1:
// buy and sell whenever previous days price is less than current days price
// add the profit to total profit

int Solution::maxProfit(const vector<int> &A) {
    int profit=0;
    if(A.size()==0) return 0;
    for(int i=0;i<A.size()-1;++i){
        if(A[i] < A[i+1]){
            // buy at i and sell at i+1
            profit+=A[i+1]-A[i];
        }
    }
    return profit;
}

// TC: O(n)
// SC: O(1)