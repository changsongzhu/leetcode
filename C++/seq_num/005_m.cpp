/**
5[M]. Longest Palindrome SubString
 
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of sis 1000.
Example:
Input: "babad"  Output: "bab"  Note: "aba" is also a valid answer.
Example:
Input: "cbbd"  Output: "bb" 
**/

/*Center Expand Solution*/
class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int len=1;
        for(int i=0;i<s.size();i++){
            int len1=expand(s, i, i);
            int len2=expand(s, i, i+1);
            int tmp=max(len1, len2);
            if(len<tmp){
                start=i-(tmp-1)/2;
                len=tmp;
            }

        }
        return s.substr(start, len);
    }
    int expand(string s, int left, int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};



class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        if(n<2) return s;
        bool dp[n][n];
        fill_n(&dp[0][0], n*n, false);
        int len=1, start=0;
        for(int j=0;j<n;j++)
        {
            dp[j][j]=true;
            for(int i=0;i<j;i++)
            {
                if((s[i]==s[j]&&(j-i<2||dp[i+1][j-1]==true))
                {
                    dp[i][j]=true;
                    if((j-i+1)>len)
                    {
                        start=i;
                        len=j-i+1;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};
