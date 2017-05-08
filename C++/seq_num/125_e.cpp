/**
125[E]. Valid Palindrome
 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

**/
class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) left++;
            else if(!isalnum(s[right])) right--;
            else if(tolower(s[left++])!=tolower(s[right--])) return false;
        }
        return true;
    }
};
