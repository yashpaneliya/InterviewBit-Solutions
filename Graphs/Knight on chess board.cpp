// https://www.interviewbit.com/problems/knight-on-chess-board/

// Approach:
// 1. We will use level order BFS to traverse the graph.
// 2. We will maintain a queue to keep track of each node in the graph.
// 3. We will maintain a visited array to keep track of which node has already visited.
// 4. We will maintain a count variable to keep track of the number of moves.
// 5. We will traverse the graph in a rookie manner until we reach the destination node.

int a,b,e,f;
vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool safe(int i, int j){
   return i > 0 && j > 0 && i <= a && j <= b;
}

// Level order BFS
int bfs(int s1, int s2)
{
    queue<pair<int, int>> q;
    q.push({s1, s2});
    vector<vector<bool>> visited(a+1, vector<bool> (b+1, false));
    visited[s1][s2] = true;
    int count = 0;
    while(!q.empty())
    {
        int size = q.size();
        count++;
        for(int k = 0; k < size; k++)
        {
            auto temp = q.front(); q.pop();
            if(temp.first == e && temp.second == f)
            {
                return count-1;
            }
            for(auto d: moves)
            {
                int x = temp.first + d.first, y = temp.second + d.second;
                if(safe(x, y) && visited[x][y] == false)
                {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
    }
    return -1;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    a=A,b=B,e=E,f=F;
    return bfs(C,D);
}

// TC: O(V^2)
// SC: O(V^2)