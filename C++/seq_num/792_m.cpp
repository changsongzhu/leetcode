/*
792. Number of Matching Subsequences

Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
*/

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<queue<string> > t(26);
        for(auto w:words){
            t[w[0]-'a'].push(w);
        }
        int res=0;
        for(int i=0;i<S.size();i++){
            int index=S[i]-'a';
            if(t[index].size()==0)continue;
            int size=t[S[i]-'a'].size();
            for(int j=0;j<size;j++){
                string tmp=t[index].front();t[index].pop();
                if(tmp.size()==1){
                    res++;
                }else{
                    t[tmp[1]-'a'].push(tmp.substr(1));
                }
            }
        }
        return res;
    }
};
