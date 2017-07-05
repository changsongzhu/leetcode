/**
576[H]. Out of boundary paths
 
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacentcell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move Ntimes. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
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
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int k = 1; k <= N; ++k) {
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    long long v1 = (x == 0) ? 1 : dp[k - 1][x - 1][y];
                    long long v2 = (x == m - 1) ? 1 : dp[k - 1][x + 1][y];
                    long long v3 = (y == 0) ? 1 : dp[k - 1][x][y - 1];
                    long long v4 = (y == n - 1) ? 1 : dp[k - 1][x][y + 1];
                    dp[k][x][y] = (v1 + v2 + v3 + v4) % 1000000007;
                }
            }
        } 
        return dp[N][i][j];
    }
};


//TLE Solution
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if(N<0) return 0;
        if(i<0||i>=m||j<0||j>=n) return 1;
        return findPaths(m, n, N-1, i-1,j)+
               findPaths(m, n, N-1, i+1,j)+
               findPaths(m, n, N-1, i, j-1)+
               findPaths(m, n, N-1, i, j+1);
        
    }
    
};

