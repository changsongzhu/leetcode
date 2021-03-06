/**
344[E]. Reverse String
Write a function that takes a string as input and returns the string reversed.
**/

class Solution { 
public:
    string reverseString(string s) {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
