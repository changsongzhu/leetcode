/**
305[H]. Number of Islands II
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example:
Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]
Challenge:
Can you do it in time complexity O(k log mn), where k is the length of the positions?
**/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if(m<=0||n<=0) return res;
        vector<int> roots(m*n, -1);
        int cnt=0;
        vector<vector<int> > dirs= {{-1, 0}, {1,0}, {0, -1}, {0, 1};
        for(auto p:positions)
        {
            int id=p.first*n+p.second;
            cnt++;
            for(auto d:dirs)
            {
                int x=p.first+d[0],y=p.second+d[1];
                int n_id=x*n+y;
                if(x<0||x>=m||y<0||y>=n||roots[n_id]==-1) continue;
                int new_id=findRoots(roots, n_id);
                if(new_id !=id)
                {
                    roots[id]=new_id;
                    id=new_id;
                    cnt--;
                }
            }
            res.push_back(cnt);
        }
    }
    int findRoots(vector<int> roots, int id)
    {
        if(roots[id] != id)
        {
           roots[id]=roots[roots[id]];
           id=roots[id];
        }
        return id;
    }
};

