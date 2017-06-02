/**
463[E]. Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
Example:
[[0,1,0,0],  [1,1,1,0],  [0,1,0,0],  [1,1,0,0]]  Answer: 16 Explanation: The perimeter is the 16 yellow stripes in the image below:  

**/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0) continue;
                int count=0;
                vector<vector<int> > offset ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for(int k=0;k<offset.size();k++)
                {
                    int x=j+offset[k][0];
                    int y=i+offset[k][1];
                    if(x>=0&&x<grid[0].size()&&y>=0&&y<grid.size()&&grid[y][x]==1) count++;
                }
                res+=(4-count);
            }
        }
        return res;
    }
};
