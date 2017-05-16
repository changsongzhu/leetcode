/**
67[E]. Add Binary
 
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100"
**/
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int n=a.size(), m=b.size();
        int carry=0;
        for(int i=0,j=0;i<n||j<m;)
        {
            if(i<n&&j<m)
            {
                int val=a[n-(i++)-1]-'0'+b[m-(j++)-1]-'0'+carry;
                carry=val/2;
                val=val%2;
                res.insert(res.begin(), val+'0');
            }
            else if(i<n&&j==m)
            {
                int val=a[n-(i++)-1]-'0'+carry;
                carry=val/2;
                val=val%2;
                res.insert(res.begin(), val+'0');
            }
            else if(i==n&&j<m)
            {
                int val=b[m-(j++)-1]-'0'+carry;
                carry=val/2;
                val=val%2;
                res.insert(res.begin(), val+'0');
            }
        }
        if(carry)
            res.insert(res.begin(), carry+'0');
        return res;
    }
};

