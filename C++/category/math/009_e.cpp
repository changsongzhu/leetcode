/**9[E]. Palindrome Number
 
Determine whether an integer is a palindrome. Do this without extra space.
 
Notes:
·      Negative Integer must not be a Palindrome Number
·      one way pass scan can solve this issue
·      Convert the number to string and then use two pointers from the begin and end to scan the string
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s=to_string(x);
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};
