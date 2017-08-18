/**
650[M]. 2 Keys Keyboard
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.


Note:
The n will be in the range [1, 1000].
**/

class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        if(n<4) return n;
        int dp[n+1]={0};
        dp[0]=0;
        dp[1]=0;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=i;
            if(i%2==0)
            {
                dp[i]=min(dp[i],dp[i/2]+2);
            }
            else
            {
                for(int j=1;j<i/2;j++)
                {
                    if(i%j==0)
                        dp[i]=min(dp[i],dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};

