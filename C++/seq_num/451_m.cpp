/**
451[M]. Sort Characters By Frequency
 
Given a string, sort it in decreasing order based on the frequency of characters.
Example 1:
Input:
"tree"
 
Output:
"eert"
 
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:
Input:
"cccaaa"
 
Output:
"cccaaa"
 
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:
Input:
"Aabb"
 
Output:
"bbAa"
 
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
**/
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        string res;
        priority_queue<pair<int, char> > q;
        for(auto c:s) mp[c]++;
        for(auto a:mp) q.push({a.second, a.first});
        while(!q.empty())
        {
            auto t=q.top();q.pop();
            res.append(t.first, t.second);
        }
        return res;
     
    }
};
