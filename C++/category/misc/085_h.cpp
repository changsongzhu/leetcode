/**
85[H]. Maximum Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
**/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=0;
        if(matrix.size()==0||matrix[0].size()==0) return res;
        int n=matrix[0].size();
        vector<int> height(n, 0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                height[j]=matrix[i][j]=='0'?0:height[j]+1;
            }
            res=max(res, largestRectangleArea(height));
        }
        return res;
    }
    int largestRectangleArea(vector<int> &height)
    {
        int res=0;
        for(int i=0;i<height.size();i++)
        {
            if(i+1<height.size()&&height[i]<height[i+1]) continue;
            int minH=height[i];
            for(int j=i;j>=0;j--)
            {
                minH=min(minH, height[j]);
                res=max(res, minH*(i-j+1));
            }
        }
        return res;
    }
};

