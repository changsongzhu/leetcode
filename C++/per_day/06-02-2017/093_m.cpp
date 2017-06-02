/**
93[M]. Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
**/
 
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        helper(res, path, s, 0, 0);
        return res;
        
    }
    void helper(vector<string> &res, string path, string s, int start, int count)
    {
        if(start>=s.size()||count>3||s.size()-start<4-count) return;

        if(count==3)
        {
            if(s.size()-start>3||stoi(s.substr(start))>255||(s.size()-start>1&&s[start]=='0')) return;
            else 
            {
                res.push_back(path+s.substr(start)); 
                return;
                
            }
        }
        for(int i=1;i<=3;i++)
        {
           if((i!=1&&s[start]=='0')||(i==3&&stoi(s.substr(start,i))>255)) continue;
           helper(res, path+s.substr(start, i)+".", s, start+i, count+1);
        }
    }
};
