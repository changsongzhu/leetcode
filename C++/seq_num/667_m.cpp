/**
667[M]. Beautiful Arrangement II
Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly kdistinct integers.
If there are multiple answers, print any of them.
Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.


Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.


Note:
The n and k are in the range 1 <= k < n <= 104.
**/

//Refined Solution
class Solution{
public:
     vector<int> constructArray(int n, int k){
          int left=1, right=k+1;
          vector<int> res;
          if(k>=n) return res;
          while(left<=right)
          {
               res.push_back(left++);
               if(left<=right) res.push_back(right--);
          }
          for(int i=k+2;i<=n;i++)
               res.push_back(i);
          return res;
     }
};


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n, -1);
        if(k>=n) return {};
        res[0]=1;
        int sign=1;
        int mx=1;
        for(int i=1;i<n;i++)
        {
            if(k==0) 
            {
                res[i]=mx+1;
                mx++;
            }
            else
            {
                int val=res[i-1]+sign*k;
                sign*=-1;
                mx=max(mx, val);
                res[i]=val;
                k--;
            }
        }
        return res;        
    }
};

