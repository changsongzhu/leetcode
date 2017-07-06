/**
239[H]. Slide Window Maximum
 
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position            	Max
[1  3  -1] -3  5  3  6  7	  3 
1 [3  -1  -3] 5  3  6  7   	3 
1  3 [-1  -3  5] 3  6  7   	5 
1  3  -1 [-3  5  3] 6  7   	5 
1  3  -1  -3 [5  3  6] 7   	6 
1  3  -1  -3  5 [3  6  7]  	7
Therefore, return the max sliding window as [3,3,5,5,6,7].
Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
**/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int> > q;
        for(int i=0;i<k;i++) q.push({nums[i], i});
        int left=0;
        if(!q.empty()) res.push_back(q.top().first);
        for(int i=k;i<nums.size();i++)
        {
            q.push({nums[i], i});
            while(!q.empty()&&q.top().second<=left) q.pop();
            res.push_back(q.top().first);
            left++;
        }
        return res;
    }
};
