/**
345[E]. Reverse Vowels of String
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
**/

class Solution {
public:
    string reverseVowels(string s) {
        int left=0, right=s.size()-1;
        while(left<right)
        {
            if(isVowel(s[left])&&isVowel(s[right]))
            {
                swap(s[left++], s[right--]);
            }
            else if(isVowel(s[left]))
                right--;
            else
                left++;
        }
        return s;
    }
private:
    bool isVowel(char c)
    {
        char tmp=tolower(c);
        if(tmp=='a'||tmp=='e'||tmp=='i'||tmp=='o'||tmp=='u') return true;
        else return false;
    }
};
