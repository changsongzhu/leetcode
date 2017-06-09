/**
361[M]. Bomb Enemy
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.
Example:
For the given grid
 
0 E 0 0
E 0 W E
0 E 0 0
 
return 3. (Placing a bomb at (1,1) kills 3 enemies)
**/
 
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.size()==0||grid[0].size()==0) return 0;
        int m=grid.size(), n=grid[0].size();
        vector<vector<int> > left(m, vector<int>(n, 0));
        vector<vector<int> > right(m, vector<int>(n, 0));
        vector<vector<int> > up(m, vector<int>(n, 0));
        vector<vector<int> > down(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]=='W') left[i][j]=0;
               else if(grid[i][j]=='E') left[i][j]=(j==0)?1:left[i][j-1]+1;
               else   left[i][j]=(j==0)?0:left[i][j-1];
            }
            for(int j=n-1;j>=0;j--){
               if(grid[i][j]=='W') right[i][j]=0;
               else if(grid[i][j]=='E') right[i][j]=(j==n-1)?1:right[i][j+1]+1;
               else   right[i][j]=(j==n-1)?0:right[i][j+1];
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
               if(grid[i][j]=='W') up[i][j]=0;
               else if(grid[i][j]=='E') up[i][j]=(i==0)?1:up[i-1][j]+1;
               else   up[i][j]=(i==0)?0:up[i-][j];
            }
            for(int i=m-1;i>=0;i--){
               if(grid[i][j]=='W') down[i][j]=0;
               else if(grid[i][j]=='E') down[i][j]=(i==m-1)?1:down[i+1][j]+1;
               else   down[i][j]=(i==m-1)?0:down[i+1][j];
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]=='0')
                   res=max(res, left[i][j]+right[i][j]+up[i][j]+down[i][j]);
            }
        }
        return res;
   }
};

