/**200[M]. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1
Example 2:
11000
11000
00100
00011
Answer: 3
**/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0||grid[0].size()==0) return 0;
        int res=0;
        vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
               if(dfs(grid, visited, i, j)) res++;
        }
        return res;
        
    }
    bool dfs(vector<vector<char> > &grid, vector<vector<bool> > &visited, int row, int col)
    {
       if(row<0||row>=grid.size()||col<0||col>=grid[row].size()) return false;
       if(visited[row][col]||grid[row][col]=='0') return false;
       visited[row][col]=true;
       dfs(grid, visited, row, col+1);
       dfs(grid, visited, row, col-1);
       dfs(grid, visited, row+1, col);
       dfs(grid, visited, row-1, col);
       return true;
    }
};

