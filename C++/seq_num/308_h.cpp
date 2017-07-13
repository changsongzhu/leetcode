/**
308[H]. Range Sum Query 2D- Mutable
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
 
sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
1.     The matrix is only modifiable by the update function.
2.     You may assume the number of calls to update and sumRegion function is distributed evenly.
3.     You may assume that row1 ≤ row2 and col1 ≤ col2.
**/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return;
        int m=matrix.size(), n=matrix[0].size();
        colSum.resize(m, vector<int>(n, 0));
        nums=matrix;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                colSum[i][j]=(i!=0)?colSum[i-1][j]+matrix[i][j]:matrix[i][j];
            }
        }

    }

    void update(int row, int col, int val) {
        int diff=val-nums[row][col];
        for(int i=row;i<nums.size();i++)
        {
            colSum[i][col]+=diff;
        }
        nums[row][col]=val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        if(row1<0||row1>=nums.size()||row<0||row2>=nums.size()) return res;
        if(col1<0||col1>=nums[0].size()||col2<0||col2>=nums[0].size()) return res;
        for(int j=col1;j<=col2;j++)
        {
            res+=(row1==0)?colSum[row2][j]:colSum[row2][j]-colSum[row1-1][j];
        }
        return res;
    }

private:
    vector<vector<int> > nums;
    vector<vector<int> > colSum;
};
