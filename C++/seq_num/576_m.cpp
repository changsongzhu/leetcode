/**
576[M]. Out of the boundary
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

Note:
Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].
**/

class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {
        unsigned int dp[51][50][50]={};
        for(int Ni=1;Ni<=N;Ni++)
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    dp[Ni][i][j]=((i==0?1:dp[Ni-1][i-1][j])+(i==m-1?1:dp[Ni-1][i+1][j])+
                                 (j==0?1:dp[Ni-1][i][j-1])+(j==n-1?1:dp[Ni-1][i][j+1]))%1000000007;
        return dp[N][x][y];        
        
    }

};
