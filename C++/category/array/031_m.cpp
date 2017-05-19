/**
31[M]. Next Permutation
 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
**/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int p_index=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1]) {p_index=i;break;}
        }
        if(p_index!=-1)
        {
            for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i]>nums[p_index]){swap(nums[i], nums[p_index]);break;}
            }
        }
        
        for(int left=p_index+1,right=nums.size()-1;left<right;)
            swap(nums[left++], nums[right--]);
    }
};
