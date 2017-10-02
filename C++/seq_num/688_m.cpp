/**
688[M]. Knight Probability in Chessboard
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly Kmoves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.
Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.


Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
**/

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K+1, vector<vector<double>>(N, vector<double>(N, -1.0)));
        return helper(dp, N, K, r, c);
    }
private:
    double helper(vector<vector<vector<double>>>& dp, int N, int k, int r, int c) {
        // if out of board, return 0.0
        if (r < 0 || r >= N || c < 0 || c >= N) return 0.0;
        // when k = 0, no more move, so it's 100% safe
        if (k == 0) return 1.0;
        if (dp[k][r][c] != -1.0) return dp[k][r][c];
        double ans = 0.0;
        ans += helper(dp, N, k-1, r-1, c-2)/8;
        ans += helper(dp, N, k-1, r-1, c+2)/8;        
        ans += helper(dp, N, k-1, r-2, c-1)/8;
        ans += helper(dp, N, k-1, r-2, c+1)/8;
        ans += helper(dp, N, k-1, r+1, c-2)/8;        
        ans += helper(dp, N, k-1, r+1, c+2)/8;
        ans += helper(dp, N, k-1, r+2, c-1)/8;
        ans += helper(dp, N, k-1, r+2, c+1)/8;        
        dp[k][r][c] = ans;
        return ans;
    }
};

