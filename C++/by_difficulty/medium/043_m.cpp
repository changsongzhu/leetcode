/**
43[M]. Multiply Strings
 
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
**/
class Solution {
public:
    string multiply(string num1, string num2) {
       int n1=num1.size(), n2=num2.size();
       string res(n1+n2, '0');
       reverse(num1.begin(), num1.end());
       reverse(num2.begin(), num2.end());
       int carry=0;
       for(int i=0;i<n2;i++)
       {
          carry=0;
          for(int j=0;j<n1;j++)
          {
              int val=(num2[i]-'0')*(num1[j]-'0');
              val=val+carry+(res[i+j]-'0');
              carry=val/10;
              val=val%10;
              res[i+j]=val+'0';
          }
          if(carry) res[n1+i]=carry+'0';
       }
       reverse(res.begin(), res.end());
       while(res.size()>1&&res[0]=='0') res.erase(res.begin());
       return res;
        
    }
};
