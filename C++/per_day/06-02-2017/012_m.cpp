/**
12[M]. Integer to Roman
 
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
**/
 
class Solution {
public:
    string intToRoman(int num) {
        int radix[]     = {1000, 900, 500, 400,  100, 90,  50,   40,   10,   9,   5,   4,    1};
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        int index=0;
        while(num)
        {
            int cnt=num/radix[index];
            num=num%radix[index];
            for(int i=0;i<cnt;i++)
                res+=symbol[index];
            index++;
        }
        return res;
    }
};

