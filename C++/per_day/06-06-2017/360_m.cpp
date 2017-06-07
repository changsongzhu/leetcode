/**
360[M]. Sort Transformed Array
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.
The returned array must be in sorted order.
Expected time complexity: O(n)
Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
Result: [3, 9, 15, 33]
nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
Result: [-23, -5, 1, 7]
**/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
         vector<int> res(nums.size());
         if(nums.size()==0) return res;
         int i=0,j=nums.size()-1;
         int k=0;
         while(i<j)
         {
             int n1=nums[i]*nums[i]*a+b*nums[i]+c;
             int n2=nums[j]*nums[j]*a+b*nums[j]+c;
             if(a>0)
             {
                 res[nums.size()-1-k]=n1>n2?n1:n2;
                 n1>n2?i++:j--;
             }
             else
             {
                 res[k]=n>n2?n2:n1;
                 n1>n2?j--:i++;
             }
             k++;
         }
         return res;
     }
};

