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
 
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
       for(int i=0;i<dictionary.size();i++)
       {
           if(dictionary[i].size()<3) mp[dictionary[i]]++;
           string tmp;
           tmp.insert(tmp.size(), dictionary[i][0])
           tmp=tmp+to_string(dictionary[i].size()-2);
           tmp.insert(tmp.size(), dictionary[i][dictionary[i].size-1]);
           mp[tmp]++;
       }
    }
    bool isUnique(string word) {
       string tmp;
       if(word.size()<3) tmp=word;
       tmp.insert(tmp.size(), word[0])
       tmp=tmp+to_string(word.size()-2);
       tmp.insert(tmp.size(), word[word.size()-1]);
       if(mp.find(tmp != mp.end()); return false;
       else return true;
 
    }
private:
   map<string, int> mp;
};

