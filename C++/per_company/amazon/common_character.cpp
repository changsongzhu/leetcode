/*
find the words in the dictionary with the letters in the str
*/

class Solution {
public:
     vector<string> commonCharacters(vector<string> &strs, string str){
         if(strs.size()==0) return {};
         vector<string> res;
         int flag=0;
          for(auto a:str) flag|=1<<(a-’a’);
          for(int i=0;i<strs.size();i++)
          {
              int tmp=0;
              for(int j=0;j<strs[i].size();j++)
                   tmp|=1<<(strs[i][j]-’a’);
              if((flag&tmp)==flag) res.push_back(strs[i]);
          }
          return res;
     }
};


/*
Note

Time Complexity: O(N*M) M is the average length of string
Space Complexity: O(1)

Optimization: Using a hashset to cache all key value for each string.

*/

