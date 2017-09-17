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

//BFS Solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0||grid[0].size()==0) return 0;
        queue<pair<int, int> > q;
        int res=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'&&visited[i][j]==false)
                {
                    res++;
                    q.push({i, j});
                    vector<vector<int> >  dirs ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    while(!q.empty())
                    {
                        int row=q.front().first,col=q.front().second;q.pop();
                        for(int k=0;k<dirs.size();k++)
                        {
                            int x=row+dirs[k][0], y=col+dirs[k][1];
                            if(x<0||x>=m||y<0||y>=n||grid[x][y]!='1'||visited[x][y]==true) continue;
                            visited[x][y]=true;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        return res;
        
    }
};



//DFS Soltuion
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

