/**
123[H]. Best Time To Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int n=prices.size();
        int g[n][3]={0},l[n][3]={0};
        for(int i=1;i<prices.size();i++)
        {
            int diff=prices[i]-prices[i-1];
            for(int j=1;j<=2;j++)
            {
                l[i][j]=max(g[i-1][j-1] + max(diff, 0), l[i-1][j]+diff);
                g[i][j]=max(g[i-1][j], l[i][j]);
            }
        }
        return g[n-1][2];
        
    }
};

