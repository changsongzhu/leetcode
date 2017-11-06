/**
498[M]. Diagonal Traversal
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:
Note:
The total number of elements of the given matrix will not exceed 10,000.
**/
//Refined Solution
class Solution{
public:
    vector<int> findDiagonalOrder(vector<vector<int> > &matrix){
        if(matrix.size()==0||matrix[0].size()==0) return {};
        vector<int> res;
        int m=matrix.size(), n=matrix[0].size();
        int cnt=0;
        int direction=1;
        int x=0, y=0;
        while(cnt<m*n){
           if(direction==1)
           {
               int i=x, j=y;
               while(i>=0&&i<m&&j>=0&&j<n){
                   res.push_back(matrix[i][j]);
                   cnt++;
                   i=i-1;j=j+1;
               }
           }
           else
           {
               int i=x, j=y;
               stack<int> stk;
               while(i>=0&&i<m&&j>=0&&j<n){
                   stk.push(matrix[i][j]);
                   i=i-1;j=j+1;
               }
               while(!stk.empty()){
                   res.push_back(stk.top());
                   stk.pop();
                   cnt++;
               }
           }
           direction*=-1;
           x<m-1?x++:y++;
        }
        return res;
    }
};



class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0||matrix[0].size()==0) return res;
        int m=matrix.size(), n=matrix[0].size();
        int cnt=0, i=0,j=0;
        int direction=-1;
        while(cnt!=m*n)
        {
            if(i<0||j>=n) direction=1;
            else if(j<0||i>=m)direction=-1;
            if(i<0&&j<n)
            {
               i=0;
            }
            else if(i>=m)
            {
                i=m-1;j=j+2;
            }
            else if(j<0&&i<m)
            {
                j=0;
            }
            else if(j>=n)
            {
                j=n-1;i=i+2;
            }
            res.push_back(matrix[i][j]);
            cnt++;
            i=i+direction;j=j-direction;
        }
        return res;
    }
};

