/**
434[E]. Number of Segment in a String
 
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
Please note that the string does not contain any non-printable characters.
Example:
Input: "Hello, my name is John" Output: 5 
**/

class Solution {
public:
    int countSegments(string s) {
        int res=0;
        s.push_back(' ');
        int start=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' '&&start==-1)
            {
                start=i;
            }
            else if(s[i]==' '&&start !=-1)
            {
                res++;
                start=-1;
            }
        }
        return res;
    }
};
