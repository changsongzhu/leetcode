/**
8[M]. String to Integer (atoi)
 
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
**/

class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0) return 0;
        int i=0;
        while(i<str.size()&&str[i]==' ')i++;
        int sign=1;
        if(i<str.size()&&(str[i]=='+'||str[i]=='-')) sign=(str[i++]=='+'?1:-1);
        int base=0;
        for(;i<str.size();i++)
        {
            if(str[i]>'9'||str[i]<'0') break;
            if(base>INT_MAX/10||(base==INT_MAX/10&&str[i]>'7'))
            {
                return sign==1?INT_MAX:INT_MIN;
            }
            base=base*10+str[i]-'0';
        }
        return base*sign;
    }
};


class Solution {
public:
    int myAtoi(string str) {
       if(str.size()==0) return 0;
       int base=0, sign=1, i=0,n=str.size();
       while(i<n&&str[i]==' ') i++;
       if(i<n&&(str[i]=='-'||str[i]=='+')) sign=(str[i++]=='+')?1:-1;
       while(i<n&&str[i]>='0'&&str[i]<='9')
       {
           if(base>INT_MAX/10||(base==INT_MAX/10&&str[i]>'7'))
               return sign==1?INT_MAX:INT_MIN;
           base=base*10+str[i++]-'0';
       }
       return sign*base;
    }
};

