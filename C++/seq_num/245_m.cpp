/**
245[M]. Shortest Word Distance 3
 
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
word1 and word2 may be the same and they represent two individual words in the list.
For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.
Note:
You may assume word1 and word2 are both in the list.
**/

//Refined Solution
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
     int index_1=-1, index_2=-1;
     int res=INT_MAX;
     for(int i=0;i<words.size();i++)
     {
         if(words[i]==word1) index_1=(word1==word2)?index_2:i;
         if(words[i]==word2) index_2=i;
         if(index_1!=-1&&index_2!=-1)
             res=min(res, abs(index_1-index_2));
     }
        return res;
    }
};


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
       int index_1=words.size();
       int index_2=-1;
       int res=INT_MAX;
       for(int i=0;i<words.size();i++)
       {
           if(words[i]==word1) index_1=word1==words2?index_2:i;
           if(words[i]==word2) index_2=i;
           res=min(res, abs(index_2-index_1));
       }
       return res;
   }
};

