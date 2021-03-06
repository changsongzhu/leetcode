/**
394[M]. Decode String
 
Given an encoded string, return it's decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
Examples:
s = "3[a]2[bc]",
return "aaabcbc".
s = "3[a2[c]]",
return "accaccacc".
s = "2[abc]3[cd]ef",
return "abcabccdcdcdef". 
**/

class Solution {
public:
    string decodeString(string s) {
       int index=0;
       return dfs(s, index);
    }
    string dfs(string s, int &index)
    {
       int cnt=0;
       string res;
       while(index<s.size())
       {
           if(s[index]>='0'&&s[index]<='9')
           {
               cnt=cnt*10+s[index++]-'0';
           }
           else if(s[index]=='[')
           {
               string tmp=dfs(s. ++index);
               for(int i=0;i<cnt;i++)
               {
                   res+=tmp;
               }
               cnt=0;
           }
           else if(s[index]==']')
           {
               index++;
               return res;
           }
           else
           {
               res.append(1, s[index++]);
           }
       }
       return res;
    }
};

