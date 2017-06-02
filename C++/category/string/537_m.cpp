/**
537[M]. Complex Number Multiplication
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:
The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
**/


class Solution {
public:
    string complexNumberMultiply(string a, string b) {
       int a_r=0,a_c=0;
       int b_r=0,b_c=0;
       auto pos=a.find_first_of('+');
       if(pos==string::npos)
       {
           a_r=stoi(a);
       }
       else
       {
           a_r=stoi(a.substr(0, pos));
           a_c=stoi(a.substr(pos+1, a.size()-pos-1));
       }
       pos=b.find_first_of('+');
       if(pos==string::npos)
       {
           b_r=stoi(b);
       }
       else
       {
           b_r=stoi(b.substr(0, pos));
           b_c=stoi(b.substr(pos+1, b.size()-pos-1));
       }
       int r=a_r*b_r-a_c*b_c;
       int c=a_r*b_c+b_r*a_c;
       return to_string(r)+"+"+to_string(c)+"i";
        
    }
};

