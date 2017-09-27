/**
413[M]. Arithmetic Slices

A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, these are arithmetic sequence:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.
1, 1, 2, 5, 7
 
 
A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
The function should return the number of arithmetic slices in the array A.
 
 
Example:
A = [1, 2, 3, 4]
 
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
**/
 
/**
f(x)=(x-1)*(x-2)/2 (x>=3)

For example:
 1, 2, 3, 4, 5

len 3: 1 2 3   2 3 4   3 4 5 (3)
len 4: 1 2 3 4   2 3 4 5    (2)
len 5: 1 2 3 4 5   (1)

f(x)= (1+(n-2+1))*(n-2)/2 = (n-1)*(n-2)/2

**/


/*DP Solution

dp[i] denotes the slices ended with nums[i]

dp[i]=dp[i-1]+1 (if nums[i], nums[i-1], nums[i-2] are arithmetic slices)
     = 0 (nums[i], nums[i-1] and nums[i-2] are not arithmetic slices)


**/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
       if(A.size()<3) return 0;
       vector<int> dp(A.size(), 0);
       int res=0;
       for(int i=2;i<A.size();i++)
       {
           if(A[i]-A[i-1]==A[i-1]-A[i-2])
           {
               dp[i]=dp[i-1]+1;
           }
           res+=dp[i];
       }
       return res;
    }
};

 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
       if(A.size()<3) return 0;
       int len=2;
       int res=0;
       for(int i=2;i<A.size();i++)
       {
           if(A[i]-A[i-1]==A[i-1]-A[i-2])
              len++;
           else
           {
              if(len>2) res+=(len-1)*(len-2)*0.5;
              len=2;
           }
       }
       if(len>2) res+=(len-1)*(len-2)*0.5;
       return res;
        
    }
};
