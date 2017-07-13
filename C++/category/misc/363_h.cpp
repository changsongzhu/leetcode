/**
363[H]. Max Sum of Rectangle No larger than K
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
**/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size();
        int sums[m][n];
        fill_n(&sums[0][0], m*n, 0);
        int res=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sums[i][j]+=matrix[i][j];
                if(i>0)  sums[i][j]+=sums[i-1][j];
                if(j>0)  sums[i][j]+=sums[i][j-1];
                if(i>0&&j>0) sums[i][j]-=sums[i-1][j-1];
                for(int r=0;r<=i;r++)
                {
                    for(int c=0;c<=j;c++)
                    {
                        int d=sums[i][j];
                        if(r>0) d-=sums[r-1][j];
                        if(c>0) d-=sums[i][c-1];
                        if(r>0&&c>0) d+=sums[r-1][c-1];
                        res=d<=k?max(d, res):res;
                    }
                }
            }
        }
        return res;
    }
};

