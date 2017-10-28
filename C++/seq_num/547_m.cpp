/**
547[M]. Friend Circles
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.
Example 1:
Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
**/
//Union Find Solution
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        int count=n;
        vector<int> parent(n, -1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j])
                {
                    int x=find(parent, i);
                    int y=find(parent, j);
                    if(x!=y)
                    {
                        parent[y]=x;
                        count--;
                    }
                }
            }
        }
        return count;
    }
    int find(vector<int>&parent, int i)
    {
        int id=i;
        while(parent[id]!=-1)
        {
            id=parent[id];
        }
        return id;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        if(n==0) return 0;
        vector<bool> visited(n, false);
        int res=0;
        for(int i=0;i<n;i++)
        {
            vector<int> path;
            dfs(M, path, visited, i);
            if(path.size()!=0) res++;
        }
        return res;
    }
    void dfs(vector<vector<int> > &M, vector<int> &res, vector<bool> &visited, int start)
    {
        if(visited[start]==true) return;
        if(start>=M.size()) return;
        res.push_back(start);
        visited[start]=true;
        for(int i=0;i<M.size();i++)
        {
            if(i==start) continue;
            if(M[start][i]==1) dfs(M, res, visited, i);
        }
    }
};

