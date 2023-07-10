// https://www.interviewbit.com/problems/valid-path/

// Approach:
// 1. We will use BFS to find the path from (0,0) to (A,B).
// 2. We will check if the current point is valid or not.
// 3. If the current point is valid, we will push it into the queue and mark it as visited.
// 4. We will repeat the above steps until the queue is empty.

bool check(int &px, int &py, vector<int> &E, vector<int> &F, int &x, int &y, int &r)
{
    if(px>x || px<0 || py>y || py<0) 
        return false;
    for(int i=0;i<E.size();i++){
        if(((E[i]-px)*(E[i]-px)+(F[i]-py)*(F[i]-py))<=r*r) 
            return false;
    }
    return true;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int dx[8]={1,0,-1,0,1,-1,-1,1};
    int dy[8]={0,1,0,-1,1,-1,1,-1};
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    bool vis[A+1][B+1];
    memset(vis,false,sizeof(vis));
    
    while(!q.empty())
    {
        auto i = q.front().first;
        auto j = q.front().second;

        q.pop();
        if(i==A && j==B) 
            return "YES";
            
        vis[i][j]=true;

        for(int k=0;k<8;k++)
        {
            int px = i + dx[k];
            int py = j + dy[k];
            if(!vis[px][py] && check(px,py,E,F,A,B,D))
            {
                q.push({px,py});
                vis[px][py]=true;
            }
        }
    }
    return "NO";
}

// TC: O(A*B*E)
// SC: O(A*B)