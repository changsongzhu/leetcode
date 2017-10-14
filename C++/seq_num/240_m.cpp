/**
240[M]. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
**/

//Refined Solution
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            j--;
        } else 
            i++;
    }
    return false;
  }
};

 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int m=matrix.size(), n=matrix[0].size();
        return helper(matrix, 0, 0, m-1, n-1, target);
    }
    bool helper(vector<vector<int> >&m, int a, int b, int c, int d, int target)
    {
        if(a>c||b>d) return false;
        if(m[a][b]>target||m[c][d]<target) return false;
        int r_m=a+(c-a)/2;
        int c_m=b+(d-b)/2;
        if(m[r_m][c_m]==target) return true;
        else if(m[r_m][c_m]>target)
        {
            return helper(m, a, b, r_m-1, c_m-1, target)||
                   helper(m, a, c_m, r_m-1, d, target)||
                   helper(m, r_m, b, c, c_m-1, target);
        }
        else
        {
            return helper(m, a, c_m+1, r_m, d, target)||
                   helper(m, r_m+1, b, c, c_m, target)||
                   helper(m, r_m+1, c_m+1, c, d, target);
        }
    }
};

