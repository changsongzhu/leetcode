/**
329[H]. Longest Increasing Path in Matrix
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
Example 1:
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].
Example 2:
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
**/
 
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int res=0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int> > visited(m, vector<int> (n, -1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                res=max(res, dfs(matrix, visited, i, j, INT_MIN));
        }
        return res;
    }
    
    int dfs(vector<vector<int> > & matrix, vector<vector<int> > &visited, int i, int j, int prev)
    {
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size()||matrix[i][j]<=prev) return 0;
        if(visited[i][j]!=-1) return visited[i][j];
        visited[i][j]=1;
        int left =dfs(matrix, visited, i,   j-1, matrix[i][j]);
        int right=dfs(matrix, visited, i,   j+1, matrix[i][j]);
        int up   =dfs(matrix, visited, i-1, j,   matrix[i][j]);
        int down =dfs(matrix, visited, i+1, j,   matrix[i][j]);
        visited[i][j]=1+max(left, max(right, max(up, down)));
        return visited[i][j];
    }
};

