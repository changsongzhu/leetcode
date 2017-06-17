309[M]. Best Time to Buy and Sell Stock with Cooldown
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

/**
buy[i] = max(sell[i-2]-price, buy[i-1])
sell[i] = max(buy[i-1]+price, sell[i-1])
**/
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.size()<2) return 0;
       vector<int> sell(prices.size(),0);
       vector<int> buy(prices.size(),0);
       sell[0]=0;buy[0]=-prices[0];
       sell[1]=max(buy[0]+prices[1],sell[0]);
       buy[1]=max(-prices[1], buy[0]);
       for(int i=2;i<prices.size();i++)
       {
          buy[i]=max(sell[i-2]-prices[i], buy[i-1]);
          sell[i]=max(buy[i-1]+prices[i], sell[i-1]);
       }
       return sell[prices.size()-1];
    }
};

