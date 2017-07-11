/**
282[H]. Expression Add Operators
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
Examples: 
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
**/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, "", res);
        return res;   
    }
    void dfs(string num, int target, long long diff, long long cur, string out, vector<string>&res)
    {
        if(cur==target||num.size()==0)
        {
            res.push_back(out);
            return;
        }
        for(int i=1;i<=num.size();i++)
        {
           string tmp=num.substr(0, i);
           if(tmp.size()>1&&tmp[0]=='0') return;
           string next=num.substr(i);
           if(out.size()>0)
           {
               dfs(next, target, -stoll(tmp), cur-stoll(tmp), out+"-"+tmp, res);
               dfs(next, target, stoll(tmp), cur+stoll(tmp), out+"+"+tmp, res);
               dfs(next, target, diff*stoll(tmp), (cur-diff)+diff*stoll(tmp), out+"*"+tmp, res);
           }
           else
           {
               dfs(next, target, stoll(tmp), stoll(tmp), out+tmp, res);
           }
        }
    }
};

