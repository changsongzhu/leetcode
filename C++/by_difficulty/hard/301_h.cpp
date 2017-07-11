/**
301[H]. Remove Invalid Parentheses
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ).
Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
**/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(s);
        ++visited[s];
        bool found = false;
        while (!q.empty()) {
            s = q.front(); q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i + 1);
                if (visited.find(t) == visited.end()) {
                    q.push(t);
                    ++visited[t];
                }
            }
        }
        return res;
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            if (t[i] == ')' && cnt-- == 0) return false;
        }
        return cnt == 0;
    }
};


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        map<string, int> m;
        dfs(s, res, m);
        return res;
    }
    void dfs(string s, vector<string> &res, map<string, int> &m)
    {
       if(m.count(s)) return;
       m[s]++;
       if(isValid(s))
       {
           if(res.size()!=0)
           {
               if(s.size()>res[0].size())res.clear();
               if(s.size()<res[0].size()) return;
           }
           res.push_back(s);
           return;
       }
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='('||s[i]==')')
               dfs(s.substr(0,i)+s.substr(i+1), res, m);
       }
    }
    bool isValid(string s)
    {
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            if(cnt<0) return false;
        }
        return cnt==0;
    }
};

