// https://www.interviewbit.com/problems/nqueens/

// Approach:
// Use backtracking to find all combinations
// Put queens row by row after checking whether that position is safe or not and move forward
// Once we reach the end of the board, add the current board to result

vector<vector<string>> res;

bool issafeplace(vector<string> board, int i, int j)
{
    // check in all row for same column
    for (int dx = 0; dx < board.size(); ++dx)
        if (board[dx][j] == 'Q')
            return false;

    // check for upper diagonal
    int x = i, y = j;
    while (x-- && y--)
    {
        if (board[x][y] == 'Q')
            return false;
    }
    // check for lower diagonal
    while (i >= 0 && j < board.size())
    {
        if (board[i--][j++] == 'Q')
            return false;
    }
    return true;
}

void util(vector<string> board, int rowindex)
{
    if (rowindex == board.size())
    {
        res.push_back(board);
        return;
    }

    for (int j = 0; j < board.size(); ++j)
    {
        if (issafeplace(board, rowindex, j))
        {
            board[rowindex][j] = 'Q'; // put queen here and move to next row
            util(board, rowindex + 1);
            board[rowindex][j] = '.'; // remove queen from here and put on next column of same row
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int A)
{
    vector<string> board(A);
    res.resize(0);
    string s = "";
    for (int i = 0; i < A; ++i)
    {
        s += ".";
    }

    for (int i = 0; i < A; ++i)
    {
        board[i] = s;
    }

    util(board, 0);

    return res;
}

// TC: O(2^n)
// SC: O(n^2)