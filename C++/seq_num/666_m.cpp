/**
666[M]. Path Sum IV
If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.
For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.
Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.


Example 2:
Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.
**/

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int dp[8][8];
        fill_n(&dp[0][0], 8*8, -1);
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int D=nums[i]/100;
            int P=(nums[i]%100)/10;
            int V=nums[i]%10;
            dp[D-1][P-1]=V;
        }
        int res=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<pow(2, i);j++)
            {
                if(dp[i][j]==-1) continue;
                dp[i][j]+=(i!=0)?dp[i-1][j/2]:0;
                if(i==3||(dp[i+1][j*2]==-1&&dp[i+1][j*2+1]==-1))
                {
                    
                    res+=dp[i][j];
                }
            }
        }
        return res;
    }
};

