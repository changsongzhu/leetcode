/**
562[M]. Longest Line of Consecutive One in Matrix
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
 
Hint: The number of elements in the given matrix will not exceed 10,000.
**/

 
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.size()==0||M[0].size()==0) return 0;
        int m=M.size(),n=M[0].size();
        vector<vector<int> > h(m vector<int>(n, 0));
        vector<vector<int> > v(m vector<int>(n, 0));
        vector<vector<int> > d(m vector<int>(n, 0));
        vector<vector<int> > a(m vector<int>(n, 0));
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    h[i][j]=(i>0)?h[i-1][j]+1:1;
                    v[i][j]=(j>0)?v[i][j-1]+1:1;
                    d[i][j]=(i>0&&j>0)?d[i-1][j-1]+1:1;
                    a[i][j]=(i>0&&j<n-1)?h[i-1][j+1]+1:1;
                    res=max(res, max(h[i][j],max(v[i][j], max(d[i][j], a[i][j]))));
                }
            }
        }
        return res;
    }
};

