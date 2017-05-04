/**
167[E]. Two Sum 2 – Input Array is Sorted
 
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

**/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        vector<int> res;
        while(left<right)
        {
            if((numbers[left]+numbers[right])==target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if((numbers[left]+numbers[right])>target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return res;
    }
};
