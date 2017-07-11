/**
273[H]. Integer to English Words
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
**/

class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string res=convertHundred(num%1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for(int i=0;i<3;i++)
        {
            num=num/1000;
            res=num%1000?convertHundred(num%1000)+ " " + v[i] + " " + res:res;
        }
        if(res.back()==' ') res.resize(res.size()-1);
        return res;
    }
    string convertHundred(int num)
    {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int a=num/100, b=num%100, c=num%10;
        string res="";
        res=b<20?v1[b]:v2[b/10]+(c>0?" " + v1[c]:"");
        if(a>0) res=v1[a]+" "+"Hundred"+(b?" "+ res:"");
        return res;
    }
};

