/**
624[E] Maximum Distance in Arrays
Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.
Example 1:
Input:
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation:
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Note:
Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].
**/

class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
            int res=0;
            int n=arrays.size();
            vector<int> right_mn(n, INT_MAX),right_mn(n, INT_MAX);
            for(int i=1;i<n;i++)
            {
                left_mn[i]=min(left_mn[i-1], arrays[i-1][0]);
            }
            for(int i=n-2;i>=0;i++)
            {
                right_mn[i]=min(right_mn[i+1], arrays[i+1][0]);
            }
            for(int i=0;i<n;i++)
               res=arrays[i]-min(left_mn[i], right_mn[i]);
            return res;
    	
	}
};

