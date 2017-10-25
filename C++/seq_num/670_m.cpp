/**
670[M]. Maximum Swap
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.


Example 2:
Input: 9973
Output: 9973
Explanation: No swap.


Note:
The given number is in the range [0, 108]
**/

//DP solution: Time Complexity: O(N)
class Solution{
public:
    int maximumSwap(int num)
    {
         string str=to_string(num);
         int n=str.size();
         vector<int>  dp(n, -1);
         int max_pos=n-1;
         for(int i=n-1;i>=0;i--)
         {
             if(str[i]>str[max_pos])
             {
                 max_pos=i;
             }
             
             dp[i]=max_pos;
            
         }
         for(int i=0;i<n;i++)
         {
             if(str[dp[i]]!=str[i])
             {
                 swap(str[i], str[dp[i]]);
                 break;
             }
         }
         return stoi(str);
    }
};



//Brute Force Soltuion: Time Complexity: O(N2)
class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string r=s;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i+1;j<s.size();j++)
            {
                swap(s[i], s[j]);
                if(s>r) r=s;
                swap(s[j], s[i]);
            }
        }
        return stoi(r);       
    }
};

