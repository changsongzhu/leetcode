/**
54[M]. Spiral Matrix
 
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[  [ 1, 2, 3 ],  [ 4, 5, 6 ],  [ 7, 8, 9 ] ]
You should return [1,2,3,6,9,8,7,4,5].

**/

//Refined Solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int m=matrix.size(), n=matrix[0].size();
        int u=0, d=m-1, l=0,r=n-1;
        while(true)
        {
            //up
            for(int i=l;i<=r;i++)res.push_back(matrix[u][i]);
            if(++u>d) break;
            //right
            for(int i=u;i<=d;i++)res.push_back(matrix[i][r]);
            if(--r<l) break;
            //down
            for(int i=r;i>=l;i--)res.push_back(matrix[d][i]);
            if(--d<u) break;
            //left
            for(int i=d;i>=u;i--)res.push_back(matrix[i][l]);
            if(++l>r) break;
        }
        return res;
    }
};


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
