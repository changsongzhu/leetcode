/**
415[E]. Add String
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
**/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int m=num1.size(),n=num2.size();
        int carry=0;
        for(int i=0,j=0;i<m||j<n;)
        {
            if(i<m&&j<n)
            {
                int val=num1[m-(i++)-1]-'0'+num2[n-(j++)-1]-'0'+carry;
                carry=val/10;
                res.insert(res.begin(), (val%10)+'0');
            }
            else if(i<m&&j==n)
            {
                int val=num1[m-(i++)-1]-'0'+carry;
                carry=val/10;
                res.insert(res.begin(), (val%10)+'0');

            }
            else if(i==m&&j<n)
            {
                int val=num2[n-(j++)-1]-'0'+carry;
                carry=val/10;
                res.insert(res.begin(), (val%10)+'0');

            }
        }
        if(carry)
            res.insert(res.begin(), carry+'0');
        return res;
    }
};
