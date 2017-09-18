/**
265[H]. Paint House II
 
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2]is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
Note:
All costs are positive integers.
Follow up:
Could you solve it in O(nk) runtime?
**/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size()==0||costs[0].size()==0) return 0;
        int min1=0,min2=0,idx=-1;
        for(int i=0;i<costs.size();i++)
        {
            int m1=INT_MAX, m2=m1, id=-1;
            for(int j=0;j<costs[i].size();j++)
            {
                int cost=costs[i][j]+((j==idx)?min2:min1);
                if(cost<m1)
                {
                    m2=m1;m1=cost;id=j;
                }
                else if(cost<m2)
                {
                    m2=cost;
                }
            }
            min1=m1;min2=m2;idx=id;
        }
        return min1;
   }
};

