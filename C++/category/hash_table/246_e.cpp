/**
246[E].  Strobogrammatic Number
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.
**/

class Solution
{
public:
    bool isStrobogrammatic(string s){
        int left=0, right=s.size()-1;
        while(left<right)
        {
            if((s[left]=='1'&&s[right]=='1')||
               (s[left]=='8'&&s[right]=='8')||
               (s[left]=='0'&&s[right]=='0')||
               (s[left]=='6'&&s[right]=='9')||
               (s[left]=='9'&&s[right]=='6'))
             {
                 left++;
                 right++;
             }
             else
             {
                 return false;
             }
        }
        if((s.size()%2)==1)
        {
            if(s[s.size()/2]!='1'&&s[s.size()/2]!='8'&&s[s.size()/2]!='0')
                return false;
        }
        return true;
    }
};

