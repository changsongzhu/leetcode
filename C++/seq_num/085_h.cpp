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
        if(matrix.size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<int> height(n, 0);
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                height[j]=(matrix[i][j]=='0'?0:height[j]+1);
            }
            res=max(res, largestRectangleArea(height));
        }
        return res;
        
        
    }
    int largestRectangleArea(vector<int> height) {
        stack<int> stk;
        height.push_back(0);
        height.insert(height.begin(), 0);
        stk.push(0);
        int res=0;
        for(int i=1;i<height.size();i++)
        {
            while(height[i]<height[stk.top()])
            {
                int index=stk.top();stk.pop();
                res=max(res, height[index]*(i-1-stk.top()));
            }
            stk.push(i);
        }
        return res;
        
    }
};

