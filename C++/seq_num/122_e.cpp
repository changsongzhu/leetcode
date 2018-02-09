/**
122[M]. Best Time to Buy and Sell Stock 2
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
**/


//DP solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        int cash=0, hold=INT_MIN;
        for(auto p:prices){
            int tmp=cash;
            cash=max(cash, hold+p);
            hold=max(hold, tmp-p);
        }
        return cash;
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                res+=(prices[i]-prices[i-1]);
        }
        return res;
    }
};
