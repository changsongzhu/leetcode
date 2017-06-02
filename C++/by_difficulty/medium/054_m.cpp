/**
54[M]. Spiral Matrix
 
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[  [ 1, 2, 3 ],  [ 4, 5, 6 ],  [ 7, 8, 9 ] ]
You should return [1,2,3,6,9,8,7,4,5].

**/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        int row=matrix.size(), col=matrix[0].size();
        int left=0,up=0,right=col-1,down=row-1;
        int cnt=0;
        while(cnt<row*col)
        {
            //left->right
            for(int i=left;i<=right&&cnt<row*col;i++)
            {
                res.push_back(matrix[up][i]);
                cnt++;
            }
            up++;
            //up->down
            for(int i=up;i<=down&&cnt<row*col;i++)
            {
                res.push_back(matrix[i][right]);
                cnt++;
            }
            right--;
            //right->left
            for(int i=right;i>=left&&cnt<row*col;i--)
            {
                res.push_back(matrix[down][i]);
                cnt++;
            }
            down--;
            //down->up
            for(int i=down;i>=up&&cnt<row*col;i--)
            {
                res.push_back(matrix[i][left]);
                cnt++;
            }
            left++;
        }
        return res;
    }
};
