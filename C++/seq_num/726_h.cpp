/*
726. Number of Atoms

Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.
Example 2:
Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:
Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Note:

All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.

*/

class Solution {
public:
    string countOfAtoms(string formula) {
        if(formula.size()==0) return "";
        map<string, int> m= parse(formula);
        string res="";
        for(auto a:m)
        {
            res+=a.first+(a.second>1?to_string(a.second):"");
        }
        return res;
    }
    map<string, int> parse(string s)
    {
        map<string, int> res;
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                int j=i;
                int cnt=0;
                while(j+1<s.size())
                {
                    if(s[j+1]=='('||(s[j+1]>='A'&&s[j+1]<='Z')) break;
                    j++;
                }
                int end=j;
                if(s[j]>='0'&&s[j]<='9')
                {
                    int mul=1;
                    while(j>i&&s[j]>='0'&&s[j]<='9')
                    {
                        cnt+=(s[j]-'0')*mul;
                        mul=mul*10;
                        j--;
                    }
                    string tmp=s.substr(i, j-i+1);
                    if(res.count(tmp)==0)
                    {
                        res[tmp]=cnt;
                    }
                    else
                    {
                        res[tmp]+=cnt;
                    }
                }
                else{
                    string tmp=s.substr(i, j-i+1);
                     if(res.count(tmp)==0)
                    {
                        res[tmp]=1;
                    }
                    else
                    {
                        res[tmp]+=1;
                    }
                }
                i=end;
            }
            else if(s[i]=='(')
            {
                int cnt=0;
                int j=i;
                while(j<s.size())
                {
                    if(s[j]=='(')cnt++;
                    else if(s[j]==')')cnt--;
                    if(cnt==0) break;
                    j++;
                }
                map<string, int> tmp=parse(s.substr(i+1, j-i-1));
                j++;
                int dup=0;
                while(j<s.size()&&s[j]>='0'&&s[j]<='9') dup=dup*10+s[j++]-'0';
                for(auto t:tmp)
                {
                    if(res.count(t.first)!=0)
                    {
                        res[t.first]+=t.second*dup;
                    }
                    else
                    {
                        res[t.first]=t.second*dup;
                    }
                }
                i=j-1;
            }
        }
        return res;
    }
};
