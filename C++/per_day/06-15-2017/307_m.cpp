/**
307[M]. Range Sum Query-Mutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]
 
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
**/

class NumArray {
public:
    NumArray(vector<int> nums) {
        bits.resize(nums.size()+1);
        data.resize(nums.size()+1);
        for(int i=0;i<nums.size();i++)
            update(i, nums[i]);
    }
    
    void update(int i, int val) {
        int tmp=data[i];
        data[i]=val;
        int diff=val-tmp;
        for(int j=i+1;j<bits.size();j+=(j&(-j)))
           bits[j]+=diff;
    }
    
    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }
    int getSum(int i)
    {
       int sum=0;
       for(int j=i;j>0;j-=(j&(-j)))
           sum+=bits[j];
       return sum;
    }
private:
    vector<int> data;
    vector<int> bits;
};
 
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

