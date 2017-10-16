/**
696[E]. Count Binary Substrings
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.
Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".


Notice that some of these substrings repeat and are counted the number of times they occur.


Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.


Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.


Note:
s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
**/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size()-1;i++){
            int zero_num=0;
            int one_num=0;
            char cur=s[i];
            int change=0;
            if(s[i]=='0') zero_num=1;
            else one_num=1;
            for(int j=i+1;j<s.size();j++)
            {

                if(s[j]!=cur) 
                {
                    cur=s[j];
                    change++;
                }
                if(change==2)
                {
                    res=((zero_num==one_num)?++res:res);
                    break;
                }
                else
                {
                    if(s[j]=='0') zero_num++;
                    else one_num++;
                    if(change==1&&zero_num==one_num)
                    {
                        res++;
                        break;
                    }
                }          
            }
        }
        return res;
        
    }
};

