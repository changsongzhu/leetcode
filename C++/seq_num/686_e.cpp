/**
686[E]. Repeated String Match
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
For example, with A = "abcd" and B = "cdabcdab".
Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
Note:
The length of A and B will be between 1 and 10000.
**/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m=A.size(),n=B.size();
        int pos=0;
        while(pos!=-1)
        {
            pos=A.find(B[0], pos);
            if(pos==-1) break;
            int i=pos, j=0;
            pos++;
            int cnt=1;
            for(;j<n;j++)
            {
                if(A[i]!=B[j]) break;
                i++;
                if(i==m&&j!=n-1) 
                {
                    cnt++;
                    i=0;
                }
            }
            if(j==n) return cnt;
        }
        return -1;     
    }
};

