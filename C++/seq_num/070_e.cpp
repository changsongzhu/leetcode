/**
70[E]. Climb Stairs
 
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> m(n+1,0);
        m[0]=m[1]=1;
        if(n<=1) return 1;
        for(int i=2;i<=n;i++)
            m[i]=m[i-1]+m[i-2];
        return m[n];
    }
};

class Solution{
public:
    int climbStairs(int n) {
        int dp[3]={0};
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
            m[i%3]=m[(i-1)%3]+m[(i-2)%3];
        return m[n%3];
    }
};
