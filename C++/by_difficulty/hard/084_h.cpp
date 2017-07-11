/**
84[H]. Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.
For example,
Given heights = [2,1,5,6,2,3],
return 10.
**/

//TLE solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            int lowest_height=heights[i];
            res=max(lowest_height, res);
            for(int j=i+1;j<n;j++)
            {
                lowest_height=min(heights[j], lowest_height);
                res=max(res, lowest_height*(j-i+1));
            }
        }
        return res;
        
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
           
            if(i+1<n&&heights[i]<=heights[i+1]) continue;
            int minH=heights[i];
            for(int j=i;j>=0;j--)
            {
                minH=min(heights[j], minH);
                res=max(res, minH*(i-j+1));
            }
        }
        return res;
        
    }
};

