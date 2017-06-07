/**
417[M]. Pacific Atlantic Water Flow
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:
Given the following 5x5 matrix:
 
  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
      	*   *   *   *   * Atlantic
 
Return:
 
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
**/
 
 
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int> > res;
        if(matrix.size()==0||matrix[0].size()==0) return res;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<bool> > pacific(m, vector<bool>(n, false));
        vector<vector<bool> > atlantic(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            dfs(pacific, matrix, INT_MIN, i, 0);
            dfs(atlantic, matrix,INT_MIN, i, n-1);
        }
        for(int i=0;i<n;i++)
        {
            dfs(pacific, matrix, INT_MIN, 0, i);
            dfs(atlantic, matrix,INT_MIN, m-1, i);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j]&&atlantic[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
    void dfs(vector<vector<bool> >&visited, vector<vector<int> >&matrix, int pre, int row, int col)
    {
        if(row<0||row>=matrix.size()||col<0||col>matrix[0].size()||visited[row][col]||pre>matrix[row][col]) return;
        visited[row][col]=true;
        dfs(visited, matrix, matrix[row][col], row-1,col);
        dfs(visited, matrix, matrix[row][col], row+1,col);
        dfs(visited, matrix, matrix[row][col], row,col-1);
        dfs(visited, matrix, matrix[row][col], row,col+1);
    }
};


