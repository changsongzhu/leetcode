/**
59[M]. Spiral Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
**/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n<=0) return vector<vector<int> > {};
        vector<vector<int> > res(n, vector<int>(n, 0));
        int left=0,right=n-1;
        int up=0,down=n-1;
        int cnt=0;
        while(cnt<n*n)
        {
           //left->right
           for(int i=left;i<=right&&cnt<n*n;i++)
           {
               res[up][i]=cnt+1;
               cnt++;
           }
           up++;
           //up->down
           for(int i=up;i<=down&&cnt<n*n;i++)
           {
               res[i][right]=cnt+1;
               cnt++;
           }
           right--;
           //right->left
           for(int i=right;i>=left&&cnt<n*n;i--)
           {
               res[down][i]=cnt+1;
               cnt++;
           }
           down--;
           //down->up
           for(int i=down;i>=up&&cnt<n*n;i--)
           {
               res[i][left]=cnt+1;
               cnt++;
           }
           left++;
           
        }
        return res;
    }
};
