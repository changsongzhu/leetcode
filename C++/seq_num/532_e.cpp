/**

532[E]. K diff Pairs in an Array
 
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].

**/
//No Sort solution
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<2) return 0;
        map<int, int> m;
        for(auto n:nums)m[n]++;
        int res=0;
        for(auto a:m)
        {
            //int tmp=res;
            if(k==0&&a.second>1)res++;
            else if(k>0)
            {
                if(m.count(a.first+k)) res++;
                if(m.count(a.first-k)) res++;
            }
            //if(res!=tmp) m.erase(a.first);         
        }
        return k==0?res:res/2;
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        map<int, int> m;
        int res=0;
        for(auto n:nums)m[n]++;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            if(k==0&&m[nums[i]]>1) res++;
            else if(k!=0&&m.find(nums[i]+k) != m.end()) res++;
        }
        return res;
    }
};
