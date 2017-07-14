/**
440[H]. K-th Smallest in Lexicographical Order
Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.
Note: 1 ≤ k ≤ n ≤ 109.
Example:
Input:
n: 13   k: 2
 
Output:
10
 
Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
**/
 

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur=1;
        k--;
        while(k>0)
        {
            long long step=0, first=cur, last=cur+1;
            while(first<=n)
            {
                step+=min((long long)n+1, last) - first;
                first*=10;
                last*=10;
            }
            if(step<=k)
            {
                cur++;
                k-=step;
            }
            else
            {
                k--;
                cur*=10;
            }
        }
        return cur;
    }
};


//TLE Solution 
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur=1;
        for(int i=0;i<k-1;i++)
        {
            if(cur*10<n)
            {
                cur=cur*10;
            }
            else
            {
                if(cur>=n)cur/=10;
                cur++;
                while(cur%10==0) cur=cur/10;
            }
            
        }
        return cur;
    }
};

