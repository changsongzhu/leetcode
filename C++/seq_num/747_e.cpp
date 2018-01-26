/*
747. Largest Number At Least Twice of Others
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
Note:
nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].

*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        struct comp{
            bool operator() (pair<int, int> p1, pair<int, int> p2){
                return p1.first>p2.first;
            } 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i], i});
            if(pq.size()>2) pq.pop();
        }
        int val=pq.top().first, index=pq.top().second; pq.pop();
        if(pq.top().first>=2*val) return pq.top().second;
        else return -1;       
    }
};
