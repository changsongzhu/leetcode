/**
651[M]. 4 Keys Keyboard
Imagine you have a special keyboard with the following keys:
Key 1: (A): Prints one 'A' on screen.
Key 2: (Ctrl-A): Select the whole screen.
Key 3: (Ctrl-C): Copy selection to buffer.
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.
Example 1:
Input: N = 3
Output: 3
Explanation: 
We can at most get 3 A's on screen by pressing following key sequence:
A, A, A


Example 2:
Input: N = 7
Output: 9
Explanation: 
We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V


Note:
1 <= N <= 50
Answers will be in the range of 32-bit signed integer.
**/

//Refined Solution 
class Solution {
public:
   int maxA(int N){
       if(N<=0) return 0;
       int dp[N+1];
       fill_n(&dp[0], N+1, 0);
       for(int i=1;i<=N;i++)
       {
           dp[i]=i;
           for(int j=0;j<i;j++)
           {
               if(i-j>=3) dp[i]=max(dp[i], (i-j-2)*dp[j]+dp[j]);
               else dp[i]=max(dp[i], dp[j]+i-j);
           }
       }
       return dp[N];
   }
};


class Solution {
public:
    int maxA(int N) {
        if(N<5) return N;
        int dp[N+1]={0};
        dp[0]=0;dp[1]=1;dp[2]=2;dp[3]=3;dp[4]=4;
        for(int i=5;i<=N;i++)
        {
            dp[i]=i;
            for(int j=i-1;j>=1;j--)
            {
                if(i-j>=3)
                {
                    dp[i]=max(dp[i],dp[j]+(i-j-2)*dp[j]);
                }
                else
                {
                    dp[i]=max(dp[i], dp[j]+(i-j));
                }
            }
        }
        return dp[N];
    }
};

