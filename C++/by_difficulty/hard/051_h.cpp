/**
51[H]. N Queens
 
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
**/

class Solution {
public:
   vector<vector<string>> solveNQueens(int n) {
      vector<vector<string> > res;
      vector<int> pos(n, -1);
      helper(res, pos, n, 0);
      return res;
   }
   void helper(vector<vector<string> > &res, vector<int> &pos, int n, int row)
   {
      if(row==n)
      {
          vector<string> tmp(n, string(n, '.'));
          for(int i=0;i<n;i++)
              tmp[i][pos[i]]='Q';
          res.push_back(tmp);
          return;
      }
      for(int i=0;i<n;i++)
      {
          pos[row]=i;
          if(isValid(pos, row, i))
              helper(res, pos, n, row+1);
          pos[row]=-1;
      }
   }
   bool isValid(vector<int> &pos, int row, int col)
   {
       for(int i=0;i<row;i++)
       {
           if(col==pos[i]||abs(row-i)==abs(col-pos[i])) return false;
       }
       return true;
   }
};

