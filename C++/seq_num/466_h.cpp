/**
466[H]. Count the Repitions
Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3]="abcabcabc".
On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.
You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.
Example:
Input:
s1="acb", n1=4
s2="ab", n2=2
 
Return:
2
**/

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(s1.size()*n1<s2.size()*n2) return 0;
        int i=0,j=0,m=0,n=0, cnt=0;
        while(m<n1)
        {
            if(s1[i++]==s2[j])
            {
                j++;
            }
            if(i==s1.size())
            {
                m++;
                i=0;
            }
            if(m==n1) break;
            if(j==s2.size())
            {
                n++;
                j=0;
            }
            if(i==0&&j==0)
            {
                return(n1/m)*n/n2;
            }
        }
        return n/n2;
    }
};

