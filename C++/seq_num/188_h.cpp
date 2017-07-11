/**
188[H]. Best Time to Buy and Sell Stock IV
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
**/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0) return 0;
        int n=prices.size();
        if(k>=n) return solveMaxProfit(prices);
        int g[k+1]={0}, l[k+1]={0};
        for(int i=1;i<prices.size();i++)
        {
            int diff=prices[i]-prices[i-1];
            for(int j=k;j>=1;j--)
            {
                l[j]=max(g[j-1]+max(diff, 0), l[j]+diff);
                g[j]=max(g[j], l[j]);
            }
        }
        return g[k];
        
    }
    int solveMaxProfit(vector<int>&prices)
    {
        int res=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                res+=prices[i]-prices[i-1];
        }
        return res;
    }
};
