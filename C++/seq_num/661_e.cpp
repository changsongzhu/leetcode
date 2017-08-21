/**
661[E]. Image Smoother
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0


Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
**/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.size()==0||M[0].size()==0) return {};
        int m=M.size(), n=M[0].size();
        vector<vector<int> >  res(m, vector<int>(n, 0));
        vector<pair<int, int> > dirs ={{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1,1}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=i, y=j;
                int val=M[i][j];
                int cnt=1;
                for(int k=0;k<8;k++)
                {
                    x=j+dirs[k].first;y=i+dirs[k].second;
                    if(x<0||x>=n||y<0||y>=m)continue;
                    val+=M[y][x];
                    cnt++;
                }
                res[i][j]=val/cnt;
            }
        }
        return res;
        
    }
};

