/**
290[E]. Word Pattern
 
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
**/

//istringstream solution
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> m1;
        map<string, int>m2;
        istringstream in(str);
        int total_size=0;
        for(int i=0;i<pattern.size();i++)
        {
            string tmp="";
            in>>tmp;
            if(tmp=="") return false;
            total_size+=tmp.size()+1;
            if(m1.find(pattern[i])!=m1.end())
            {
                if(m2.find(tmp)==m2.end()||m2[tmp]!=m1[pattern[i]]) return false;
            }
            else
            {
                m1[pattern[i]]=i;
                if(m2.find(tmp)!=m2.end()) return false;
                m2[tmp]=i;
            }
        }
        return in.str().size()==(total_size-1);
    }
};


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        if(str.size()==0) return false;
        int index=0;
        int i=0;
        while(i<str.size())
        {
           if(str[i]==' ')
           {
               strs.push_back(str.substr(index, i-index));
               index=i+1;
           }
           i++;
        }
        strs.push_back(str.substr(index, str.size()-index));

        if(strs.size() != pattern.size()) return false;

        map<char, int> mp1;
        map<string,int>mp2;
        for(int i=0;i<pattern.size();i++)
        {
            if(mp1.find(pattern[i]) == mp1.end()&&mp2.find(strs[i])==mp2.end())
            {
                mp1[pattern[i]]=i;
                mp2[strs[i]]=i;
            }
            else if(mp1.find(pattern[i]) != mp1.end()&&mp2.find(strs[i])!=mp2.end()&&mp1[pattern[i]]==mp2[strs[i]])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
