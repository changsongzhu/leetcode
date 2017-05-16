/**
541[E]. Reverse String II
 
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
**/

class Solution {
public:
	string reverseStr(string s, int k) {
           int length=s.size();
           for(int i=0;i<s.size();)
           {
               int remain=length-i;
               int reverse_size=(remain>=k)?k:remain;
               int process_size=(remain>=2*k)?2*k:remain;
               int left=i,right=i+reverse_size-1;
               while(left<right)
               {
                   swap(s[left++],s[right--]);
               }
               i=i+process_size;
           }
           return s;
	}
};
