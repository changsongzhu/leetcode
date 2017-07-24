/**
11[M]. Container with Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.
**/

//Two Pointers: Time Complexity: O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
       int res=0;
       for(int i=0,j=height.size()-1;i<j;)
       {
           res=max(res, min(height[i],height[j])*(j-i));
           height[i]<height[j]?i++:j--;
       }
       return res;
    }
};

//Brute Force Solution: Time Complexity: O(n2)
class Solution {
public:
    int maxArea(vector<int>& height) {
       int res=0;
       for(int i=1;i<height.size();i++)
       {
           for(int j=i-1;j<i-1;j++)
           {
               res=max(res, min(height[i], height[j])*(i-j));
           }
       }
       return res;
    }
};
