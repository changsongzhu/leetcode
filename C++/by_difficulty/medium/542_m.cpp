/**
542[M]. 01 Matrix
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Example 1: 
Input:
0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:
0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
**/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
       int m=matrix.size(),n=matrix[0].size();
       vector<vector<int> > dist(m, vector<int>(n, INT_MAX));
       vector<vector<int> > dirs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
       queue<pair<int, int> > q;
       for(int i=0;i<m;i++)
       {
          for(int j=0;j<n;j++)
          {
              if(matrix[i][j]==0)
              {
                  q.push({i, j});
                  dist[i][j]=0;
              }
          }
       }
       while(!q.empty())
       {
           auto t=q.front();q.pop();
           int distance=dist[t.first][t.second];
           for(auto d:dirs)
           {
               int x=t.first+d[0], y=t.second+d[1];
               if(x<0||y<0||x>=m||y>=n||matrix[x][y]==0) continue;
               if(dist[x][y]>distance+1)
               {
                   dist[x][y]=distance+1;
                   q.push({x, y});
               }

           }

       }

       return dist;
    }
};

