711[H]. Number of Distinct Islands II
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

Example 1:
11000
10000
00001
00011
Given the above grid map, return 1. 

Notice that:
11
1
and
 1
11
are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
Example 2:
11100
10001
01001
01110
Given the above grid map, return 2.

Here are the two distinct islands:
111
1
and
1
1

Notice that:
111
1
and
1
111
are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.
Note: The length of each dimension in the given grid does not exceed 50.

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
        
        vector<vector<pair<int, int> > > t(8);
        for(auto p:path){
            t[0].push_back({p.first, p.second});
            t[1].push_back({p.first, -p.second});
            t[2].push_back({-p.first, p.second});
            t[3].push_back({-p.first, -p.second});
            t[4].push_back({p.second, p.first});
            t[5].push_back({p.second, -p.first});
            t[6].push_back({-p.second, p.first});
            t[7].push_back({-p.second, -p.first});
        }
        
        for(auto &a:t)sort(a.begin(), a.end());
        for(auto &a:t){
            for(int i=1;i<a.size();i++){
                a[i].first-=a[0].first;
                a[i].second-=a[0].second;
            }
            a[0].first=a[0].second=0;
        }
        sort(t.begin(), t.end());
        return t[0];

    }
    
    int numDistinctIslands2(vector<vector<int>>& grid) {
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


//Refined Solution
class Solution {
public:
    void dfs(vector<vector<int> > &grid, int x, int y, vector<pair<int, int>>&path, int cnt)
    {
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]!=1) return;
        path.push_back({x, y});
        grid[x][y]=cnt;
        dfs(grid, x-1, y, path, cnt);
        dfs(grid, x+1, y, path, cnt);
        dfs(grid, x, y-1, path, cnt);
        dfs(grid, x, y+1, path, cnt);
    }
    vector<pair<int, int>>norm(vector<pair<int, int> >&path)
    {
        vector<vector<pair<int, int>>> s(8);
        for(auto p:path)
        {
            int x=p.first, y=p.second;
            s[0].push_back({x, y});
            s[1].push_back({-x, y});
            s[2].push_back({x, -y});
            s[3].push_back({-x, -y});
            s[4].push_back({y, x});
            s[5].push_back({-y,x});
            s[6].push_back({y, -x});
            s[7].push_back({-y,-x});
        }
        for(auto &a:s) sort(a.begin(), a.end());
        for(auto &a:s)
        {
            for(int i=1;i<a.size();i++)
            {
                a[i].first-=a[0].first;
                a[i].second-=a[0].second;
            }
            a[0].first=a[0].second=0;
        }
        sort(s.begin(), s.end());
        return s[0];
    }
    int numDistinctIslands2(vector<vector<int> > &grids){
        if(grids.size()==0||grids[0].size()==0) return 0;
        int m=grids.size(), n=grids[0].size();
        set<vector<pair<int, int>>> s;
        for(int i=0;i<m;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(grids[i][j]==1)
               {
                   vector<pair<int, int> > path;
                   dfs(grids, i, j, path, 2);
                   vector<pair<int, int>> r=norm(path);
                   s.insert(r);
               }
           }
        }
        return s.size();
    }

};



class Solution {
public:
    map<int, vector<pair<int,int>>> mp;
    
    void dfs(int r, int c, vector<vector<int>> &g, int cnt) {
        if ( r < 0 || c < 0 || r >= g.size() || c >= g[0].size()) return;
        if (g[r][c] != 1) return;
        g[r][c] = cnt;
        mp[cnt].push_back({r,c});
        dfs(r+1,c,g,cnt);
        dfs(r-1,c,g,cnt);
        dfs(r,c+1,g,cnt);
        dfs(r,c-1,g,cnt);
    }
    
    vector<pair<int,int>> norm(vector<pair<int,int>> v) {
        vector<vector<pair<int,int>>> s(8);
        // compute rotations/reflections.
        for (auto p:v) {
            int x = p.first, y = p.second;
            s[0].push_back({x,y});
            s[1].push_back({x,-y});
            s[2].push_back({-x,y});
            s[3].push_back({-x,-y});
            s[4].push_back({y,-x});
            s[5].push_back({-y,x});
            s[6].push_back({-y,-x});
            s[7].push_back({y,x});
        }
        for (auto &l:s) sort(l.begin(),l.end());
        for (auto &l:s) {
            for (int i = 1; i < v.size(); ++i) 
                l[i] = {l[i].first-l[0].first, l[i].second - l[0].second};
            l[0] = {0,0};
        }
        sort(s.begin(),s.end());
        return s[0];
    }
    
    int numDistinctIslands2(vector<vector<int>>& g) {
        int cnt = 1;
        set<vector<pair<int,int>>> s;
        for (int i = 0; i < g.size(); ++i) for (int j = 0; j < g[i].size(); ++j) if (g[i][j] == 1) {
            dfs(i,j,g, ++cnt);
            s.insert(norm(mp[cnt]));
        }
        
        return s.size();
    }
};
