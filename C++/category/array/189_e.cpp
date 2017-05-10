/**
189[E]. Rotate Array
 
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
**/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0) return;
        k=k%nums.size();
        for(int i=0;i<k;i++)
        {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};
