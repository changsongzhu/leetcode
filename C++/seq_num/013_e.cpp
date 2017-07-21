/**
13[E]. Roman to Integer
 
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

**/

class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(i>0&&map(s[i])>map(s[i-1]))
                res -=2*map(s[i-1]);
            res +=map(s[i]);
        }
        return res;
    }
    int map(char c)
    {
        switch(c)
        {
            case 'M':return 1000;
            case 'D':return 500;
            case 'C':return 100;
            case 'L':return 50;
            case 'X':return 10;
            case 'V':return 5;
            case 'I':return 1;
            default: return 0;
        }
    }
};

//Refined Version
class Solution {
public:
    int romanToInt(string s) {;
        map<char, int> m;
        m['M']=1000;m['D']=500;m['C']=100;m['L']=50;m['X']=10;m['V']=5;m['I']=1;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(i>0&&m[s[i]]>m[s[i-1]]) res-=2*m[s[i-1]];
            res+=m[s[i]];
        }
        return res;
    }
};
