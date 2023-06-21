// https://www.interviewbit.com/problems/points-on-the-straight-line/

// Approach:
// For each point, calculate the slope with all other points
// If the slope is same, the points are on the same line
// Keep track of the maximum number of points on the same line

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    
    int n=A.size();
    
    if(n<=2) return n;
    
    int res=1;
    
    for(int i=0;i<A.size()-1;++i){
        unordered_map<double, int> hash;
        int p1x=A[i];
        int p1y=B[i];
        int same=0;
        int temp=0;
        
        for(int j=i+1;j<A.size();++j){
            int p2x=A[j];
            int p2y=B[j];
            double slope;
            
            if(p1x==p2x && p1y==p2y)
            {
                ++same;
                continue;
            }
            else if(p2x == p1x)
                slope = INT_MAX;
            else
                slope = (double)(p2y - p1y) / (p2x - p1x);
                
            hash[slope]++;
        }
        
        for(auto x:hash)
            temp = max(temp, x.second);
        
        ++temp; // for the ith point
        temp+=same; // to include overlapping points
        res=max(res, temp);
    }
    
    return res;
}

// TC: O(N^2)
// SC: O(N^2)