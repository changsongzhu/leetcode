/**
256[E]. Paint House
 
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
Note:
All costs are positive integers.
**/

class Solution
{
public:
    int paintHouse(vector<vector<int> > &prices)
        if(prices.size()==0) return 0;
        if(prices.size()==1) return min(prices[0][0], min(prices[0][1], prices[0][2]));
        vector<vector<int> > cost(prices.size()+1,vector<int>(3, 0));
        cost[0][0]=cost[0][1]=cost[0][2]=0;
        cost[1][0]=prices[0][0];
        cost[1][1]=prices[0][1];
        cost[1][2]=prices[0][2];
        for(int i=2;i<=prices.size();i++)
        {
            cost[i][0]=prices[i-1][0]+min(cost[i-1][1], cost[i-1][2]);
            cost[i][1]=prices[i-1][1]+min(cost[i-1][0], cost[i-1][2]);
            cost[i][2]=prices[i-1][2]+min(cost[i-1][0], cost[i-1][1]);
        }
        return min(min(cost[prices.size()][0],cost[prices.size()][1]),cost[prices.size()][2]);
    }
};
