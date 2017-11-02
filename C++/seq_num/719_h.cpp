/**
719[H]. Find K-th Smallest Pair Distance
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

**/


//maxHeap Solution BUT TLE

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k){
       priority_queue<pair<int, int> >pq;
       for(int i=0;i<nums.size();i++)
       {
           for(int j=i+1;j<nums.size();j++)
           {
               pq.push({abs(nums[i]-nums[j]), i<<16|j});
               if(pq.size()>k) pq.pop();
           }
       }
       return pq.size()==k?pq.top().first:0;

    }
};

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
       int count[1000001]={0};
       fill_n(&count[0], 1000001, 0);
       for(int i=0;i<nums.size();i++)
       {
           for(int j=i+1;j<nums.size();j++)
           {
               count[abs(nums[i]-nums[j])]++;
           }
       }
       for(int i=0;i<1000001;i++)
       {
           k-=count[i];
           if(k<=0) return i;
       }
       return 0;
    }
};
