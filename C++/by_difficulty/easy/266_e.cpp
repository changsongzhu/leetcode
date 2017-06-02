/**
266[E]. Palindrome Permutation 
Given a string, determine if a permutation of the string could form a palindrome.
For example,
"code" -> False, "aab" -> True, "carerac" -> True.
Hint:
·   	Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
**/

class Solution
{
public:
    bool hasPalindrome(string s){
        map<char, int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int odd_count=0;
        for(map<char, int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            if((it->second/2)==1) odd_count++;
        }
        if(odd_count>1) return false;
        else return true;
    }
};
