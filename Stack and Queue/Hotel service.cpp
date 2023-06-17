// https://www.interviewbit.com/problems/hotel-service/discussion/p/multisource-bfs/200024/2584/

// Approach:
// Multisource BFS
// Push all hotels in queue
// For each hotel, perform BFS and store distance of each cell from hotel
// If distance of cell is less than previous distance, then update distance

bool isvalid(int i, int j, int row, int col){
    if(i<row && i>=0 && j<col && j>=0)
        return true;
    return false;
}

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int> res;
    
    queue<pair<int,int>> q;
        
    int row=A.size();
    int col=A[0].size();
    
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
    // vector<vector<int,bool>> visited(row, vector<int>(col,false));
    
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j){
            if(A[i][j]==1)
            {
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int x=q.front().first;
            int y=q.front().second;
            
            q.pop();
            
            if(isvalid(x-1,y,row,col)){
                if(dist[x-1][y]>dist[x][y]+1)
                {
                    dist[x-1][y] = dist[x][y]+1;
                    q.push({x-1,y});
                }
            }
            
            if(isvalid(x,y-1,row,col)){
                if(dist[x][y-1]>dist[x][y]+1)
                {
                    dist[x][y-1] = dist[x][y]+1;
                    q.push({x,y-1});
                }
            }
            
            if(isvalid(x+1,y,row,col)){
                if(dist[x+1][y]>dist[x][y]+1)
                {
                    dist[x+1][y] = dist[x][y]+1;
                    q.push({x+1,y});
                }
            }
            
            if(isvalid(x,y+1,row,col)){
                if(dist[x][y+1]>dist[x][y]+1)
                {
                    dist[x][y+1] = dist[x][y]+1;
                    q.push({x,y+1});
                }
            }
        }
    }
    
    for(auto q:B){
        res.push_back(dist[q[0]-1][q[1]-1]);
    }
    
    return res;
}

// TC: O(n*m)
// SC: O(n*m)