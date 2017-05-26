/**
187[M]. Repeated DNA Sequences
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 
Return:
["AAAAACCCCC", "CCCCCAAAAA"].
**/
 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        vector<string> res;
        if(s.size()<=10) return res;
        for(int i=0;i<=s.size()-10;i++)
        {
            string key= s.substr(i, 10);
            mp[key]++;
            if(mp[key]==2) res.push_back(key);
        }
        return res;
        
    }
};

