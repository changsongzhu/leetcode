/**72[H]. Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
**/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++) dp[i][0]=i;
        for(int j=0;j<=n2;j++) dp[0][j]=j;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(word1[i-1]==word2[j-1])
                   dp[i][j]=dp[i-1][j-1];
                else
                   dp[i][j]=min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
        }
        return dp[n1][n2];
    }
};

