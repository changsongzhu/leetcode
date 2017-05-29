/**166[M]. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
**/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1=numerator>=0?1:-1;
        int s2=denominator>=0?1:-1;  
        map<long long, int> mp;
        string res="";
        long long num=abs((long long)numerator);
        long long den= abs((long long)denominator);
        long long out=0;
        long long rem=0;
        out=num/den;
        rem=num%den;
        if(s1*s2<0&&(out>0||rem>0)) res+="-";
        if(rem==0) return res+to_string(out);
        res+=to_string(out)+".";
        num=rem;
        while(num!=0)
        {
            rem=(num*10)%den;
            out=(num*10)/den;
            if(mp.count(num))
            {
                res.insert(mp[num],"(");
                res.push_back(')');
                return res;
            }
            else
            {
                mp[num]=res.size();
                res+=to_string(out);
                num=rem;
            }
        }
        return res;
    }
};
