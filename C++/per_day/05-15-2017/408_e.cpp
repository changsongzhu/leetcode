/**
408[E]. Valid Word Abbreviation
 
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.
A string such as "word" contains only the following valid abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.
Example 1:
Given s = "internationalization", abbr = "i12iz4n":  Return true.
 
Example 2:
Given s = "apple", abbr = "a2e":  Return false.
**/

class Solution
{
public:
    bool validAbbrev(string str, string abr)
    {
        for(int i=0,j=0;i<str.size()&&j<abr.size();)
        {
            int count=0;
            while(abr[j]>='0'&&abr[j]<='9'&&j<abr.size())
            {
              count=count*10+abr[j]-'0';
              j++;
            }
            i=i+count;
            if(i>=str.size()||str[i]!=abr[j]) return false;
        }  
        return true;
    }
};

