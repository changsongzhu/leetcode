/**

411[H]. Minimum Unique Word Abbreviation
A string such as "word" contains the following abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with thesmallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.
Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.
Note:
·       In the case of multiple answers as shown in the second example below, you may return any one of them.
·       Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
 
Examples:
"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")
 
"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").
**/



class Solution {
public:
    typedef priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > my_pq;

    string minAbbreviation(string target, vector<string>& dictionary) {
        my_pq q;
        q=generate(target);
        while(!q.empty())
        {
            auto t=q.top(); q.pop();
            bool no_conflict=true;
            for(auto d:dictionary)
            {
                if(valid(d, t.second))
                {
                    no_conflict=false;
                    break;
                }
            }
            if(no_conflict==true) return t.second;
        }   
    
        return "";
    }

    my_pq generate(string target)
    {
        my_pq res;
        for(int i=0;i<pow(2, target.size());i++)
        {
            int cnt=0, size=0;
            string out="";
            for(int j=0;j<target.size();j++)
            {
                if((i>>j)&1)cnt++;
                else
                {
                    if(cnt!=0)
                    {

                       out+=to_string(cnt);
                       cnt=0;
                       size++;
                    }
                    out+=target[j];
                    size++;
                }
            }
            if(cnt>0)
            {
               out+=to_string(cnt);
               size++;
            }
            res.push({size, out});
        }
    }

    bool valid(string word, string abbr)
    {
        int m=word.size(), n=abbr.size(), p=0;
        for(int i=0;i<n;)
        {
            if(abbr[i]>='0'&&abbr[i]<='9')
            {
                int cnt=0;
                while(i<n&&abbr[i]>='0'&&abbr[i]<='9') cnt=cnt*10+abbr[i++]-'0';
                p=p+cnt;
            }
            else
            {
                if(p>=m||word[p++]!=abbr[i++]) return false;
            }
        }
        return p==m;
    }
};




