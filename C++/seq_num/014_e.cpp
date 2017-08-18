/**
14[E]. Longest Common Prefix (LCP)
 
Write a function to find the longest common prefix string amongst an array of strings.
 
 
Notes:
·   	Vertical Scan the strings in the array until find the first different
**/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j].size()<=i||strs[j][i]!=strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
