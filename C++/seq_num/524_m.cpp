/**
524[M].Longest Word in Dictionary through deleting
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]
 
Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]
 
Output:
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
**/
 
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
       string result="";
       for(int i=0;i<d.size();i++)
       {
          int j=0,cnt=0;
          while(j<s.size()&&cnt<d[i].size())
          {
              if(s[j++]==d[i][cnt]) cnt++;
          }
          if(cnt==d[i].size())
          {
             if(d[i].size()==result.size())
             {
                 result=result>d[i]?d[i]:result;
             }
             else
             {
                 result=result.size()<d[i].size()?d[i]:result;
             }
          }
       }
       return result;
        
    }
};

