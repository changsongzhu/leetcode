/**
639[H]. Decode Ways II
A message containing letters from A-Z is being encoded to numbers using the following mapping way:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.
Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
Also, since the answer may be very large, you should return the output mod 109 + 7.
Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
**/

class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0) return 0;
        int M = 1000000007;
        int n=s.size();
        vector<long long> dp(n+1, 0);
        dp[0]=1;
        dp[1]=s[0]=='*'?9:s[0]=='0'?0:1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]<'0'&&s[i-1]>'9'&&s[i-1]!='*') return 0;
            if(s[i-1]=='*')
            {
                dp[i]=9*dp[i-1];
                if(s[i-2]=='1')
                    dp[i]=(dp[i]+9*dp[i-2])%M;
                else if(s[i-2]=='2')
                    dp[i]=(dp[i]+6*dp[i-2])%M;
                else if(s[i-2]=='*')
                    dp[i]=(dp[i]+15*dp[i-2])%M;
            }
            else
            {
                dp[i]=s[i-1]=='0'?0:dp[i-1];
                if(s[i-2]=='1')
                   dp[i]=(dp[i]+dp[i-2])%M;
                else if(s[i-2]=='2'&&s[i-1]<='6')
                   dp[i]=(dp[i]+dp[i-2])%M;
                else if(s[i-2]=='*')
                   dp[i]=(dp[i]+(s[i-1]<='6'?2:1)*dp[i-2])%M;
            }
        }
        return (int)dp[n];
        
    }
};

