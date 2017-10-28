/**
288[M]. Unique Word Abbreviation
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
a) it                      --> it (no abbreviation)
 	1
b) d|o|g                   --> d1g
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n
      1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]  isUnique("dear") -> false isUnique("cart") -> true isUnique("cane") -> false isUnique("make") -> true
**/
class ValidWordAbbr{
public:
    ValidWordAbbr(vector<string> dictionary) {
       for(int i=0;i<dictionary.size();i++)
       {
           //Handle the duplicate case
           if(dict.count(dictionary[i])) continue;
           dict[dictionary[i]]++;
           abbr[getAbbr(dictionary[i])]++;
       }
    }
    
    bool isUnique(string word)
    {
        string abr=getAbbr(word);
        //if the word is in the dictionary and appear only ONE time, it is unique
        if(dict.count(word)!=0&&abbr[abr]==1) return true;
        if(abbr.count(abr)) return false;
        else return true;
    }
private:
    string getAbbr(string s)
    {
        return s.size()<3?s:(string(1, s[0])+to_string(s.size()-2)+string(1, s[s.size()-1]));
    }
    unordered_map<string, int> dict;
    unordered_map<string, int> abbr;
};

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
       for(int i=0;i<dictionary.size();i++)
       {
           if(dict.find(dictionary[i])!=dict.end())
               continue;
           else
               dict[dictionary[i]]++;
           if(dictionary[i].size()<3) mp[dictionary[i]]++;
           else   
           {
               string tmp;
                tmp.insert(tmp.end(), dictionary[i][0]);
                tmp=tmp+to_string(dictionary[i].size()-2);
                tmp.insert(tmp.end(), dictionary[i][dictionary[i].size()-1]);
                mp[tmp]++;
           }
       }
    }
    bool isUnique(string word) {
        string tmp;
       if(word.size()<3) tmp=word;
       else
       {
           tmp.insert(tmp.end(), word[0]);
           tmp=tmp+to_string(word.size()-2);
           tmp.insert(tmp.end(), word[word.size()-1]);
       }
       if(dict.find(word)!=dict.end()&&mp[tmp]==1) return true;
       if(mp.find(tmp) != mp.end()) return false;
       else return true;
 
    }
private:
   map<string, int> mp;
   map<string, int>dict;
}; 
