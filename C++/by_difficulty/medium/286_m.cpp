/**
286[M]. Walls and Gates
You are given a m x n 2D grid initialized with these three possible values.
1.     -1 - A wall or an obstacle.
2.     0 - A gate.
3.     INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
**/

class Solution {
public:
   void wallsAndGates(vector<vector<int>>& rooms) {
       int m=rooms.size();
       int n=room[0].size();
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
              vector<vector<bool> > visited(m, vector<bool>(n, false));
              if(rooms[i][j]==0)
              {
                  dfs(rooms, visited, 1, i-1, j);
                  dfs(rooms, visited, 1, i+1, j);
                  dfs(rooms, visited, 1, i, j-1);
                  dfs(rooms, visited, 1, i, j+1);
              }
           }
       }
   }
   void dfs(vector<vector<int> >&rooms, vector<vector<int> > &visited, int distance, int row, int col)
   {
       if(row<0||rom>=rooms.size()||col<0||col>=rooms[0].size()) return;
       if(rooms[row][col]!=-1||visited[row][col]==true) return;
       visited[row][col]=true;
       rooms[row][col]=min(rooms[row][col], distance);
       dfs(rooms, visited, distance+1, row-1, col);
       dfs(rooms, visited, distance+1, row+1, col);
       dfs(rooms, visited, distance+1, row, col-1);
       dfs(rooms, visited, distance+1, row, col+1);
   }
};

