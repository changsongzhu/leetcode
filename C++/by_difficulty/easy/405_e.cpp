/**
405[E]. Convert a Number to Hexadecimal
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
Note:
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
**/

class Solution {
public:
    string toHex(int num) {
       string res="";
       for(int i=0;num&&i<8;i++)
       {
           int t=num&0xF;
           if(t>=10) res=char(t-10+'a') + res;
           else res=char(t+'0') + res;
           num=num>>4;
       }
       return res.empty()?"0":res;
        
    }
};
