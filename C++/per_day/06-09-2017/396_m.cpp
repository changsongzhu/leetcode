/**
396[M]. Rotate Function
Given an array of integers A and let n to be its length.
Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:
F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
Calculate the maximum value of F(0), F(1), ..., F(n-1).
Note:
n is guaranteed to be less than 105.
Example:
A = [4, 3, 2, 6]
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26 
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
**/
 
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
       int n=A.size();
       vector<int> B(n, 0);
       for(int i=0;i<n;i++) B[i]=i;
       int res=INT_MIN;
       for(int i=0;i<n;i++)
       {
           int sum=0;
           for(int i=0;i<n;i++)
           {
               sum+=A[i]*B[i];
               B[i]=(B[i]+1)%n;
           }
           res=max(res, sum);
       }
       return res;
    }
};

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
       int sum=0, res=0, f=0;
       for(int i=0;i<A.size();i++) {sum+=A[i];f+=i*A[i];}
       res=f;
       for(int i=1;i<A.size();i++)
       {
           f=f+sum-A.size()*A[A.size()-i];
           res=max(res, f);
       }
       return res;
    }
};

