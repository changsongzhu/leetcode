/**
694[M]. Number of Distinct Islands
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
Example 1:
11000
11000
00011
00011


Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1


and
1
11


are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
**/
/*Refined Solution*/
class Solution {
public:

    void dfs(vector<vector<int> >&grid, int x, int y, vector<pair<int, int> > &path, vector<vector<bool> > &visited){
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]!=1||visited[x][y]==true) return;
        visited[x][y]=true;
        path.push_back({x, y});
        dfs(grid, x-1, y, path, visited);
        dfs(grid, x+1, y, path, visited);
        dfs(grid, x, y-1, path, visited);
        dfs(grid, x, y+1, path, visited);
    }
    
    vector<pair<int,int> > norm(vector<pair<int, int> > &path){
        sort(path.begin(), path.end());
        for(int i=1;i<path.size();i++){
            path[i].first-=path[0].first;
            path[i].second-=path[0].second;
        }
        path[0].first=path[0].second=0;
        return path;

    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0)return 0;
        int m=grid.size(),n=grid[0].size();
        set<vector<pair<int, int> > > s;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]==false){
                    vector<pair<int, int> > path;
                    dfs(grid, i, j, path, visited);
                    s.insert(norm(path));
                }
            }
        }
        return s.size();
        
    }
};


//Refine Solution
class Solution{
public:
    void dfs(vector<vector<int>> &grid, int x, int y, vector<pair<int, int> > &path, int cnt)
    {
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]!=1) return;
        path.push_back({x, y});
        grid[x][y]=cnt;
        dfs(grid, x-1, y, path, cnt);
        dfs(grid, x+1, y, path, cnt);
        dfs(grid, x, y-1, path, cnt);
        dfs(grid, x, y+1, path, cnt);
    }
    void norm(vector<pair<int, int> > &path)
    {
        sort(path.begin(), path.end());
        for(int i=1;i<path.size();i++)
        {
            path[i].first-=path[0].first;
            path[i].second-=path[0].second;
        }
        path[0].first=path[0].second=0;
    }
    int numDistinctIslands(vector<vector<int> > &grid){
        if(grid.size()==0||grid[0].size()==0) return 0;
        int m=grid.size(), n=grid[0].size();
        set<vector<pair<int, int>>>s;
        for(int i=0;i<m;i++)
        {
           for(int j=0;j<n;j++)
           {
               vector<pair<int, int>> path;
               if(grid[i][j]==1)
               {
                   dfs(grid, i, j, path, 2);
                   norm(path);
                   s.insert(path);
               }
           }
        }
        return s.size();
    }
};



class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0) return 0;
        int m=grid.size(), n=grid[0].size();
        set<set<int>> s;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    vector<int> path;
                    set<int> tmp;
                    dfs(grid, i, j, path);
                    tmp.insert(0);
                    for(int k=1;k<path.size();k++)
                    {
                        tmp.insert((((path[k]>>16)-i)*n)+((path[k]&0xFFFF)-j));
                    }
                    s.insert(tmp);
                    
                }
            }
        }
        return s.size();       
    }
    
    void dfs(vector<vector<int> > &m, int x, int y, vector<int> &path)
    {
        if(x<0||x>=m.size()||y<0||y>=m[x].size()||m[x][y]!=1) return;
        path.push_back((x<<16)|y);
        m[x][y]=2;
        dfs(m, x-1, y, path);
        dfs(m, x, y-1, path);
        dfs(m, x+1, y, path);
        dfs(m, x, y+1, path);
    }
};

