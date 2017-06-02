/**

17[M]. Letter Combinations of a Phone Number
 
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

**/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
            vector<vector<char> > m = {{' '},{' '},{'a','b','c'},
                                   {'d','e','f'},{'g','h','i'},{'j','k','l'},
                                   {'m','n','o'},{'p','q','r','s'},{'t','u','v'},
                                   {'w','x','y','z'}};
         vector<string> res;
         string path;
         if(digits.size()<=0) return res;
         helper(res, path, m, digits, 0);
         return res;
     }
     void helper(vector<string> &res, string path, vector<vector<char> > &dict, string &digits, int start)
     {
         if(start==digits.size())
         {
             res.push_back(path);
             return;
         }
         if(digits[start]=='0'||digits[start]=='1')
             helper(res, path, dict, digits, start+1);
         else
         {
             for(int i=0;i<dict[digits[start]-'0'].size();i++)
             {
                 helper(res, path+string(1, dict[digits[start]-'0'][i]), dict, digits, start+1);
             }
         }
     }
};
