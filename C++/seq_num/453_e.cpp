/**
453[E]. Minimum Moves to Equal Array Elements
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
Example:
Input:
[1,2,3]
 
Output:
3
 
Explanation:
Only three moves are needed (remember each move increments two elements):
 
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
**/

//Math Solution
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        int sum=0;
        for(auto a:nums)
        {
            mn=min(mn, a);
            sum+=a;
        }
        return sum-mn*n;
    }
};



class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int min_val=INT_MAX;
        for(auto num:nums) 
            min_val=min(min_val, num);
        
        for(auto num:nums)
            sum+=(num-min_val);

        return sum;
    }
};
