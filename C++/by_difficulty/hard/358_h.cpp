/**
358[H]. Rearrange String k Distance Apart
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".
Example 1:
str = "aabbcc", k = 3
 
Result: "abcabc"
 
The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3
 
Answer: ""
 
It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2
 
Answer: "abacabcd"
 
Another possible answer is: "abcabcda"
 
The same letters are at least distance 2 from each other.
**/
 
class Solution {
public:
    string rearrangeString(string str, int k) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for(auto s:str) m[s]++;
        for(auto it=m.begin();it!=m.end();it++) q.push_back({it.second, it->first});
        string res="";
        int len=str.size();
        while(!q.empty())
        {
            vector<pair<int, char> > v;
            int cnt=min(k, len);
            for(int i=0;i<cnt;i++)
            {
                if(q.empty()) return "";
                auto a=q.top();q.pop();
                a.first--;
                res.push_back(a.second);
                if(a.first>0) v.push_back(a);
                len--;
            }
            for(auto a:v) q.push_back(a);
        }
        return res;
   }
};

