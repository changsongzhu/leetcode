#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <set>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<3) return true;
        int cnt=0;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<prev)
            {
               cnt++;
            }
            else
                prev=nums[i];
        }
        return cnt<=1;
    }
};

int main(void)
{
    Solution solution;
    vector<int> nums(3, 0);
    nums[0]=4;
    nums[1]=2;
    nums[2]=1;
    bool res=solution.checkPossibility(nums);
    cout<<"Result: " << res<<endl;

    return 0;
}
