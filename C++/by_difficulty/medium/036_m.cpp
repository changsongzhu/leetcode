/**
36[M]. Valid Sudoku
 
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
**/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9||board[0].size()!=9) return false;

        //Check the rows
        for(int i=0;i<9;i++)
        {
            map<char, int> mp;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.'&&board[i][j]<'1'&&board[i][j]>'9') return false;
                if(board[i][j]!='.')
                {
                   mp[board[i][j]]++;
                   if(mp[board[i][j]]>1) return false;
                }
            }
        }
        //Check the col
        for(int j=0;j<9;j++)
        {
            map<char, int> mp;
            for(int i=0;i<9;i++)
            {
                if(board[i][j]!='.'&&board[i][j]<'1'&&board[i][j]>'9') return false;
                if(board[i][j]!='.')
                {
                   mp[board[i][j]]++;
                   if(mp[board[i][j]]>1) return false;
                }
            }
        }
        vector<vector<int> > dir ={{0,0}, {0, 3}, {0, 6},{3,0},{3,3}, {3,6},{6,0},{6,3},{6,6}};
        //Each sub-block
        for(int k=0;k<9;k++)
        {
            map<char, int>mp;
            for(int i=dir[k][0];i<dir[k][0]+3;i++)
            {
                for(int j=dir[k][1];j<dir[k][1]+3;j++)
                {
                    if(board[i][j]!='.'&&board[i][j]<'1'&&board[i][j]>'9') return false;
                    if(board[i][j]!='.')
                    {
                       mp[board[i][j]]++;
                       if(mp[board[i][j]]>1) return false;
                    }
                }
            }
        }
        return true;
    }
};

