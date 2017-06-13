/**
616[M]. Add Bold Tag in String
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:
Input:
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input:
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
**/
 
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        map<string, int> mp;
        set<int> len;
        for(auto d:dict){
            len.insert(d.size());
            mp[d]++;
        }
        vector<vector<int> > range;
        int right=-1;
        int left=-1;
        for(int i=0;i<s.size();i++){
            for(auto j:len){
                if(mp.find(s.substr(i, j)) !=mp.end()){
                    if(left==-1){
                        left=i;
                        right=max(right, i+j-1);
                    }
                    else{
                        right=max(right, i+j-1);
                    }
                }
            }
            if(right!=-1&&right<i){
                range.push_back({i, right});
                left=right=-1;
            }
        }
        string res;
        int start=0;
        for(int i=0;i<range.size();i++){
           if(start<range[i][0])
               res=res+s.substr(start, range[i][0]-start);
           res="<b>"+s.substr(range[i][0], range[i][1]-range[i][0]+1) +"</b>";
           start=range[i][1]+1;
        }
        if(start<s.size())
            res+=s.substr(start);
        return res;
    }
};

