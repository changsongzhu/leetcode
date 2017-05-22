/**
79[M]. Word Search
 
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[  
['A','B','C','E'],  
['S','F','C','S'],  
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
**/

 class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        if(board.size()==0) return false;
        vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(used, board, word, i,j, 0)==true)
                   return true;
            }
        }
        return false;
        
   }
   bool dfs(vector<vector<bool> >&used, vector<vector<char> >&board, string word, int i, int j, int index)
   {
       if(index==word.size()) return true;
       if(i<0||i>=board.size()) return false;
       if(j<0||j>=board[0].size())return false;
       if(used[i][j]==true||board[i][j]!=word[index]) return false;
       bool res=false;
       used[i][j]=true;
       res=dfs(used, board, word, i-1,j,index+1)||
           dfs(used, board, word, i+1,j,index+1)||
           dfs(used, board, word, i,j-1,index+1)||
           dfs(used, board, word, i,j+1,index+1);
       used[i][j]=false;
       return res;
   }
};
