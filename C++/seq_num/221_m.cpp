/**

221[M]. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
**/


//DP Solution
class Solution {
public:
    int maximalSquare(vector<vector<char>>&matrix){
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size();
	int mx=0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++) { dp[i][0]=(matrix[i][0]=='1'?1:0); mx=max(mx, dp[i][0]);}
        for(int i=0;i<n;i++) { dp[0][i]=(matrix[0][i]=='1'?1:0); mx=max(mx, dp[0][i]);}
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=matrix[i][j]=='1'?min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1:0;
                mx=max(mx, dp[i][j]);
            }
        }
        return mx*mx;
    }
};


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int> > sums(m, vector<int>(n, 0));
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int t=matrix[i][j]-'0';
                if(i>0) t+=sums[i-1][j];
                if(j>0) t+=sums[i][j-1];
                if(i>0&&j>0) t-=sums[i-1][j-1];
                sums[i][j]=t;
                if(matrix[i][j]=='1')
                {
                   int cnt=1;
                   
                   for(int k=min(i,j);k>=0;k--)
                   {
                      int d=sums[i][j];
                      if(i-cnt>=0) d-=sums[i-cnt][j];
                      if(j-cnt>=0) d-=sums[i][j-cnt];
                      if(i-cnt>=0&&j-cnt>=0) d+=sums[i-cnt][j-cnt];
                      if(d==cnt*cnt) res=max(res,d);
                      cnt++;
                   }
                }
            }
        }
        return res;
    }
};
