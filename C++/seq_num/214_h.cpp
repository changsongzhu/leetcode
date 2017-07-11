/**
214[H]. Shortest Palindrome
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
**/

class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.size(), i=0;
        for(i=n;i>=0;i--)
        {
            if(s.substr(0, i)==t.substr(n-i))
                break;
        }
        return t.substr(0, n-i) + s;
    }
};

