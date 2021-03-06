/**
168[E]. Excel Sheet Column Title
 
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
1 -> A 	
2 -> B 	
3 -> C 	
... 	
26 -> Z 	
27 -> AA 	
28 -> AB

**/
/**
26  -> Z   1
52  -> AZ  2
78  -> BZ  3
**/


//Refined Solution
class Solution {
public:
    string convertToTitle(int n){
         string res="";
         while(n>0)
         {
              res.insert(res.begin(), --n%26+'A');
              n=n/26;
         }
         return res;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n>0)
        {
            int val=n%26;
            if(val==0)
            {
                res.insert(res.begin(), 'Z');
                n=n/26-1;
            }
            else
            {
                res.insert(res.begin(), val-1+'A');
                n=n/26;
            }
        }
        return res;
    }
};
