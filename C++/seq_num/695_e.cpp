/**
695[E]. Max Area of Island
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
**/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0&&grid[0].size()==0) return 0;
        int m=grid.size(), n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int area=0;
                dfs(grid, i, j, area);
                res=max(res, area);
                
            }
        }
        return res;
    }
    void dfs(vector<vector<int> > &g, int x, int y, int &area)
    {
        if(x<0||x>=g.size()||y<0||y>=g[x].size()||g[x][y]!=1) return;
        area++;
        g[x][y]=2;
        dfs(g, x+1, y, area);
        dfs(g, x-1, y, area);
        dfs(g, x, y-1, area);
        dfs(g, x, y+1, area);
    }
};

