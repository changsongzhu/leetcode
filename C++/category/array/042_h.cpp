/**
42[H]. Trapping Rain Water
 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
**/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int n=height.size();
        vector<int> left_mx(n, 0);
        vector<int> right_mx(n,0);
        for(int i=0;i<n;i++)
            left_mx[i]=(i==0)?height[i]:max(left_mx[i-1], height[i]);
        for(int i=n-1;i>=0;i--)
            right_mx[i]=(i==n-1)?height[i]:max(right_mx[i+1], height[i]);
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=min(left_mx[i], right_mx[i])-height[i];
        }
        return res;
    }
};

