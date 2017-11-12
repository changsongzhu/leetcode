/*
727. Minimum Window Subsequence

Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:
Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/

class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char, vector<int> > m;
        for(int i=0;i<S.size();i++)
        {
            if(m.count(S[i]))
                m[S[i]].push_back(i);
            else
                m[S[i]]={i};
        }
        int start=-1;
        int len=INT_MAX;
        if(m.count(T[0])==0) return"";
        for(auto i:m[T[0]])
        {
            int index=0;
            int j=0;
            for(j=i;j<S.size();j++)
            {
                if(S[j]==T[index])
                {
                    index++;
                    if(index!=T.size()&&(m.count(T[index])==0||(j+1)>m[T[index]].back())) break;
                }
                if(index==T.size()) break;
                
            }
            if(index==T.size()&&j-i+1<len)
            {
                start=i;
                len=j-i+1;
            }
        }
        return len==INT_MAX?"":S.substr(start, len);
        
    }
};
