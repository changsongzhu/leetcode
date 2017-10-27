/**
648. Replace Words

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.
Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.
You need to output the sentence after the replacement.
Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"


Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
**/

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        istringstream is(sentence);
        vector<string> words;
        string tmp;
        while(is>>tmp) words.push_back(tmp);
        map<string, int> m;
        for(auto w:dict)m[w]++;
        for(int i=0;i<words.size();i++)
        {
            for(int j=1;j<=words.size();j++)
            {
                if(m.count(words[i].substr(0, j)))
                {
                    words[i]=words[i].substr(0, j);
                    break;
                }
            }
        }
        string res;
        for(auto w:words)
            res+=w+" ";
        res.pop_back();
        return res;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        map<string, int> m;
        for(auto w:dict)m[w]++;
        string res="";
        sentence.push_back(' ');
        for(int i=0;i<sentence.size();)
        {
            int j=i;
            while(j<sentence.size()&&sentence[j]!=' ')
            {
                if(m.count(sentence.substr(i, j-i+1))!=0) {res+=sentence.substr(i, j-i+1)+" "; break;}
                j++;
            }
            if(sentence[j]==' ') {
                res+=sentence.substr(i, j-i)+" ";
            }else { 
                while(sentence[j]!=' ') 
                    j++;
            }
            i=j+1;
        }
        if(res.back()==' ') res.pop_back();
        return res;
        
    }
};

