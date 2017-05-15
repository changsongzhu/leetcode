/**
38[E]. Count and Say
 
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
**/

class Solution {
public:
    string countAndSay(int n) {
        if(n<=0) return "";
        string res="1";
        for(int i=1;i<n;i++)
        {
            string tmp="";
            res.push_back('*');
            int count=0;
            for(int j=0;j<res.size();j++)
            {
               if(j==0) 
               {
                   count++;
                   continue;
               }
               if(res[j]!=res[j-1])
               {
                   tmp.push_back(count+'0');
                   tmp.push_back(res[j-1]);
                   count=1;
               }
               else
               {
                   count++;
               }
                
            }
            res=tmp;
        }
        return res;
    }
};
