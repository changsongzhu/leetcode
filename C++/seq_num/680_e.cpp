/**
680[E]. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
Example 1:
Input: "aba"
Output: True


Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.


Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
**/

/*Another Solution*/
class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, false);
    }
    
    bool valid(string s, bool deleted){
        if(s.size()<2) return true;
        int left=0,right=s.size()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                if(deleted==true)return false;
                return valid(s.substr(left, right-left), true)||valid(s.substr(left+1, right-left), true);
            }
        }
        return true; 
    }

};


class Solution {
public:
    bool validPalindrome(string s) {
        if(valid(s)) return true;
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(s[left]!=s[right]) break;
            left++;
            right--;
        }
        if(valid(s.substr(0, left)+s.substr(left+1))||valid(s.substr(0, right)+s.substr(right+1))) return true;
        return false;       
    }
    bool valid(string s)
    {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
};

