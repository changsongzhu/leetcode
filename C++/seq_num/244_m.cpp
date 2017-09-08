/**
244[M]. Shortest Word Distance 2
 
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
**/

 
class WordDistance {
public:
    WordDistance(vector<string> words) {
	for(int i=0;i<words.size();i++)
           mp[words[i]].push_back(i);    
    }

    int shortest(string word1, string word2) {
        int res=INT_MAX;
        int i=0,j=0;
        while(i<mp[word1].size()&&j<mp[word2].size())
        {
            res=min(res, abs(mp[word1][i]-mp[word2][j]));
            if(mp[word1][i]<mp[word2][j]) i++;
            else j++;
        }
        return res;
    }
private:
    map<string, vector<int> > mp;
};

