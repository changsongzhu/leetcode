/**
130[M]. Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
**/

//Refined Solution
class Solution{
public:
    void solve(vector<vector<char>>  &board){
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if((i==0||i==board.size()-1||j==0||j==board[0].size()-1)&&board[i][j]=='O')
                    dfs(board, i, j);
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='*') board[i][j]='O';
            }
        }

    }
    void dfs(vector<vector<char> >&board, int x, int y)
    {
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]!='O') return;
        board[x][y]='*';
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
               if((i==0||j==0||i==board.size()-1||j==board[i].size()-1)&&board[i][j]=='O')
                   dfs(board, i, j);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='*') board[i][j]='O';

            }
        }

    }
    void dfs(vector<vector<char> > &board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '*';
            if (i > 0 && board[i - 1][j] == 'O') 
                dfs(board, i - 1, j);
            if (j < board[i].size() - 1 && board[i][j + 1] == 'O') 
                dfs(board, i, j + 1);
            if (i < board.size() - 1 && board[i + 1][j] == 'O') 
                dfs(board, i + 1, j);
            if (j > 0 && board[i][j - 1] == 'O') 
                dfs(board, i, j - 1);
        }
    }
};
