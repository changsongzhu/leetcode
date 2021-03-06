/**
462[M]. Minimum Moves to Equal Array Elements
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
You may assume the array's length is at most 10,000.
Example:
Input:
[1,2,3]
Output:
2
 Explanation:
Only two moves are needed (remember each move increments or decrements one element):
 [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
**/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=0,j=nums.size()-1;
        sort(nums.begin(), nums.end());
        int res=0;
        while(i<j)
        {
            res+=nums[j--]-nums[i++];
        }
        return res;
        
    }
};
 

