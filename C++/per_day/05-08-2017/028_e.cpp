/**

28[E]. Implement strStr()
 
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

**/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int start_index  = 0;
        int needle_index = 0;
        int cur_index    = start_index;

        while(start_index != haystack.size() && needle_index != needle.size())
        {
            if(haystack[cur_index] == needle[needle_index])
            {
                cur_index++;
                needle_index++;
            }
            else
            {
               start_index++;
               cur_index    = start_index;
               needle_index =0;
            }
        }
        if(needle_index == needle.size())return start_index;
        else return -1;
    }
};

class Solution2 {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        if(m<n) return -1;
        
        if(n==0) return 0;
        
        for(int i=0;i<m;i++)
        {
            int size = min(m-i, n);   
            if(haystack.substr(i, size) == needle)
                return i;
        }
        return -1;
    }
};
