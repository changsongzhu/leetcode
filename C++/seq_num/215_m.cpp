/**
215[M]. Kth Largest Element  in an Array
 
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
**/


//Quick Select: Space Complexity O(1), Time Complexity O(N)
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k)
    {
         return find(nums, 0, nums.size()-1, nums.size()-k);
    }
    int find(vector<int>&nums, int start, int end, int k)
    {
         if(start>end) return INT_MAX;
         int pivot=nums[end];
         int left=start;
         for(int i=start;i<end;i++)
         {
             if(nums[i]<=pivot) swap(nums[left++], nums[i]);
         }
         swap(nums[left], nums[end]);
         if(left==k) return nums[left];
         else if(left<k) return find(nums, left+1, end, k);
         else return find(nums, start, left-1, k);
    }
};


//Priority Queue: Space Complexity O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        struct comp{
          bool operator()(int a, int b)
          {
              return a>b;
          }
        };
        priority_queue<int, vector<int>, comp> q;
        for(int i=0;i<nums.size();i++)
        {
            q.push(nums[i]);
            if(q.size()>k)
            {
                q.pop();
            }
        }
        return q.top();
    }
};


//Using priority_queue Solution : Space Complexity O(N)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for(int i=0;i<k-1;i++)
            q.pop();
        return q.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

