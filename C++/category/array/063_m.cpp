/**
63[M]. Unique Path 2
 
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[  
[0,0,0],  
[0,1,0],  
[0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
**/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0||obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int> > path(m, vector<int>(n, 0));;
        path[0][0]=1;
        for(int i=1;i<n;i++)
            path[0][i]=(obstacleGrid[0][i]!=1)?path[0][i-1]:0;
        for(int i=1;i<m;i++)
            path[i][0]=(obstacleGrid[i][0]!=1)?path[i-1][0]:0;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                path[i][j]=(obstacleGrid[i][j]==1)?0:(path[i-1][j]+path[i][j-1]);
            }
        }
        return path[m-1][n-1];
    }
};
