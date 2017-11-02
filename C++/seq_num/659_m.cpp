/**
659[M]. Split Array Into Consecutive Subsequence
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5


Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5


Example 3:
Input: [1,2,3,4,4,5]
Output: False


Note:
The length of the input is in range of [1, 10000]
**/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int> > > m;
        int count=0;
        for(auto n:nums)
        {
             if(!m[n-1].empty())
             {
                 int len=m[n-1].top();
                 m[n-1].pop();
                 m[n].push(len+1);
                 if(len+1==3) count--;
             }
             else
             {
                 m[n].push(1);
                 count++;
             }
        }
        return count==0;
        
    }
};
