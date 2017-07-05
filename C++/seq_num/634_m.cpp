/**634[M]. Find the Derangement of An Array
In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.
There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.
Also, since the answer may be very large, you should return the output mod 109 + 7.
Example 1:
Input: 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
Note:
n is in the range of [1, 106].
**/

/*
DP equation: D(n)=(n-1)*(D(n-1)+D(n-2));
*/

class Solution {
public:
    int findDerangement(int n) {
        long long res=n==0?0:1;
        long long d1=0,d2=1;
        for(int i=3;i<=n;i++)
        {
            res=(n-1)*(d1+d2)%1000000007;
            d1=d2;
	    d2=res;
        }
        return res;
    }
};

