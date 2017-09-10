/**
675[H]. Cut off Trees For Golf Event
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:
0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).
You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.
You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.
Example 1:
Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6


Example 2:
Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1


Example 3:
Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.


Hint: size of the given matrix will not exceed 50x50.
**/

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.size()==0) return -1;
        map<int, int>mp;
        int m=forest.size(), n=forest[0].size();
        for(int i=0;i<forest.size();i++)
        {
            for(int j=0;j<forest[i].size();j++)
            {
                if(forest[i][j]>1)
                    mp[forest[i][j]]=((i<<16)|j);
            }
        }
        int sx=0,sy=0;
        int res=0;
        map<int, int> dist;
        while(!mp.empty())
        {
            auto it=mp.begin();
            int ex=((it->second>>16)&0xFFFF), ey=(it->second&0xFFFF);
            int d=distance(forest, sx, sy, ex, ey);
            if(d==-1) return -1;
            else res+=d;
            mp.erase(mp.begin());
            sx=ex;
            sy=ey;
        }
        return res;
    }

    int distance(vector<vector<int> >&f, int sx, int sy, int ex, int ey)
    {
        if(sx==ex&&sy==ey) return 0;
        int m=f.size(), n=f[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        queue<pair<int, int> > q;
        q.push({(sx<<16)|sy, 0});
        vector<pair<int, int> > dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[sx][sy]=true;
        while(!q.empty())
        {
                int val=q.front().first, level=q.front().second;
                q.pop();
                int r=val>>16, c=val&0xFFFF;
                for(int i=0;i<4;i++)
                {
                    int x=r+dir[i].first,y=c+dir[i].second;
                    if(x<0||x>=m||y<0||y>=n||visited[x][y]==true||f[x][y]==0) continue;
                    if(x==ex&&y==ey) return level+1;
                    visited[x][y]=true;
                    q.push({x<<16|y, level+1});
                }  
        }  
        return -1;
    }  
};

