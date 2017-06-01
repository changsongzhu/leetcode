/**
71[M]. Simplify Path
 
Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.
Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
**/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string res;
        if(path[path.size()-1]!='/')path.push_back('/');
        if(path[0]!='/') return res;
        for(int i=1;i<path.size();)
        {
            int index=i;
            while(index<path.size())
            {
               if(path[index]=='/') break;
               else index++;
            
            }
            string tmp=path.substr(i,index-i+1);
            if(tmp=="../")
            {
                if(!stk.empty())stk.pop();
            }
            else if(tmp=="/"||tmp=="./")
            {
            }
            else
            {
                stk.push(tmp);
            }
            i=index+1;       
        }
        while(!stk.empty())
        {
            res=stk.top()+res;
            stk.pop();
        }
        res="/"+res;
        if(res[res.size()-1]=='/'&&res.size()!=1) res.pop_back();
        return res;
    }
};
