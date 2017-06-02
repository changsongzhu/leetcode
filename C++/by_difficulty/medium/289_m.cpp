/**
289[M]. Game of Life
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.
Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
**/

//State Machine
// 1: live->dead; 2:live->live 3: dead->live 0: dead->dead
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0||board[0].size()==0) return;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
               vector<vector<int> > dir = {{-1,-1},{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
               int live_cnt=0;
               for(int k=0;k<dir.size();k++)
               {
                   int row=i+dir[k][0];
                   int col=i+dir[k][1];
                   if(row>=0&&row<board.size()&&col>=0&&col<board[0].size()&&(board[row][col]==1||board[row][col]==2)) live_cnt++;
               }
               if(board[i][j]==1)
               {
                   if(live_cnt>3||live_cnt<2) board[i][j]=1;
                   else board[i][j]=2;
               }
               else
               {
                   //state 3
                   if(live_cnt==3) board[i][j]=3;
               }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==1||board[i][j]==0) board[i][j]=0;
                else board[i][j]=1;
            }
        }
        
    }
};

