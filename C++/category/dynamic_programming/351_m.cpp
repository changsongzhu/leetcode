/**
351[M]. Android Unlock Pattern
 
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
Rules for a valid pattern:
1.     Each pattern must connect at least m keys and at most n keys.
2.     All the keys must be distinct.
3.     If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
4.     The order of keys used matters.
 
Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
 
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.
Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.
Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
Example:
Given m = 1, n = 1, return 9.

**/
 
class Solution {
public:
    int numberOfPatterns(int m, int n) {
       vector<vector<int> > jump(10, vector<int>(10, 0));
       int res=0;
       jump[1][3]=jump[3][1]=2;jump[4][6]=jump[6][4]=5;jump[7][9]=jump[9][7]=8;
       jump[1][7]=jump[7][1]=4;jump[2][8]=jump[8][2]=5;jump[3][9]=jump[9][3]=6;
       jump[1][9]=jump[9][1]=5;jump[3][7]=jump[7][3]=5;
       res+=helper(1, 0, 0, jump, m, n, visited)*4;
       res+=helper(2, 0, 0, jump, m, n, visited)*4;
       res+=helper(5, 0, 0, jump, m, n, visited);
       return res; 
       
   }
   int helper(int num, int len, int res, vector<vector<int> > &jump, int m, int n, vector<vector<bool> >&visited)
   {
       if(len>=m) res++;
       len++;
       if(len>n) return res;
       visited[num]=true;
       for(int i=1;i<=9;i++)
       {
          int j=jump[num][i];
          if(!visited[i]&&(j==0||visited[j]))
              helper(i, len, res, jump, m, n, visited);
       }
       visited[num]=false;
       return res;
   }
};

