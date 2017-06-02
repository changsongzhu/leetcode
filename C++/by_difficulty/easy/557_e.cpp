/**557[E]. Reverse Words in String III
 
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
**/
class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return "";
        int start=0;
        for(int i=0;i<s.size();i++)
        {
            if(i==s.size()-1||s[i]==' ')
            {
                int left=start,right=(s[i]==' ')?i-1:i;
                while(left<right)
                   swap(s[left++], s[right--]);
                start=i+1;
            }
        }
        return s;
    }
};
