/**
658[M]. Find K Closest Elements
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]


Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]


Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
**/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start =0;
        for(int i=k;i<arr.size();i++)
        {
            if(abs(arr[i]-x)<abs(arr[start]-x)||arr[i]==arr[start]) start++;
        }
        vector<int> res;
        for(int i=start;i<start+k;i++)
            res.push_back(arr[i]);
        return res;
        
    }
};
