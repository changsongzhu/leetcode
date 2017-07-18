/**
317[H] Shortest Distance from all buildings
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
·       Each 0 marks an empty land which you can pass by freely.
·       Each 1 marks a building which you cannot pass through.
·       Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
**/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int res=INT_MAX, val=0;
        vector<vector<int> > sum = grid;
        vector<vector<int> > dirs ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    queue<pair<int, int> > q;
                    vector<vector<int> >  dist=grid;
                    res=INT_MAX;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        int a=q.top().first, b=q.top().second; q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int x=a+dirs[k][0], y=b+dirs[k][1];
                            if(x<0||x>=m||y<0||y>=n||grid[x][y]!=val) continue;
                            --grid[x][y];
                            dist[x][y]=dist[a][b]+1;
                            sum[x][y]+=dist[x][y]-1;
                            q.push({x, y});
                            res=min(res, sum[x][y]);
                        }
                    }
                }
                val--;
            }
        }
        return res==INT_MAX?-1:res;
    }
};

