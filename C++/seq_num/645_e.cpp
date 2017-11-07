/**645[E]. Set Mismatch

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]


Note:
The given array size will in the range [2, 10000].
The given array's numbe
rs won't have any order.
**/
//Refined Solution
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i+1&&nums[i]!=nums[nums[i]-1]) 
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1) return {nums[i], i+1};
        }
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> m;
        vector<int> res(2);
        for(auto a:nums)m[a]++;
        for(int i=1;i<=nums.size();i++)
        {
            if(m.count(i)==0) res[1]=i;
            else if(m[i]==2) res[0]=i;
        }
        return res;
    }
};

