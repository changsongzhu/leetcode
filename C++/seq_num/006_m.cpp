/**
6[M]. ZigZag Conversion
 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**/
 
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()<=numRows||numRows==1) return s;
        string res;
        for(int i=0;i<numRows;i++)
        {
            int index=i;
            while(index<s.size())
            {
                res.append(1, s[index]);
                if(i!=0&&i!=numRows-1&&(index+2*numRows-2-2*i)<s.size())
                    res.append(1, s[index+2*numRows-2-2*i]);
                index=index+2*numRows-2;
            }
        }
        return res;
    }
};


/**
Extended Questions:

If the ZigZag pattern is as following:
Y   I   R
A P L S I I N
P   A   H   G
**/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string res;
        for(int i=numRows-1;i>=0;i--)
        {
           int index=i;
           while(index<s.size())
           {
               res.append(1, s[index]);
               if(i!=numRows-1&&i!=0&&(index+2*numRows-2-2*(numRows-1-i))<s.size())
                   res.append(1, s[index+2*numsRows-2-2*(numRows-1-i)]);
               index=index+2*numRows-2;
           }
        }
        return res;
    }
};



