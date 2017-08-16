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

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<int> sizes;
        int len=0;
        int start=nums[0]-1;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=(start+1)){
                sizes.push_back(1);
                start=nums[i];
                len=1;
                i++;
            }
            else{
                int j=len;
                for(int m=0;j>0;j--,m++) {
                    if(i<nums.size()&&nums[i]==(start+1)){
                       sizes[sizes.size()-1-m]++;
                       i++;
                    }
                    else
                       break;
                }
                if(j>0) len=len-j;
                else{
                   while(i<nums.size()&&nums[i]==(start+1)) {
                       i++; 
                       sizes.push_back(1);
                       len++;
                   }
                }
                start=start+1;
            }
        }

        for(int k=0;k<sizes.size();k++){
            if(sizes[k]<3) return false;
        }
        return true;
    }
};

