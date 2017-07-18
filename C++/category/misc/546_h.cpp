/**
546[H]. Remove Boxes
Given several boxes with different colors represented by different positive numbers. 
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.
Example 1:
Input:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
----> [1, 3, 3, 4, 3, 1] (3*3=9 points)
----> [1, 3, 3, 3, 1] (1*1=1 points)
----> [1, 1] (3*3=9 points)
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.
**/

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
       int n=boxes.size();
       int dp[100][100][100]={0};
       return dfs(boxes, 0, n-1, 0, dp);     
    }
    int dfs(vector<int> &boxes, int i, int j, int k, int dp[100][100][100])
    {
        if(j<i) return 0;
        if(dp[i][j][k]>0) return dp[i][j][k];
        int res=(k+1)*(k+1)+dfs(boxes, i+1, j, 0, dp);
        for(int m=i+1;m<=j;m++)
        {
            if(boxes[m]==boxes[i])
                res=max(res, dfs(boxes, i+1, m-1, 0, dp)+dfs(boxes, m, j, k+1, dp));
        }
        return dp[i][j][k]=res;
    }
};

