/**
69[E]. Sqrt(x)
 
Implement int sqrt(int x).
Compute and return the square root of x.
**/
class Solution {
public:
    int mySqrt(int x) {
        long left=0,right=x;
        long mid=left+(right-left)/2;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(mid*mid>x)
            {
                right=mid-1;
            }
            else if(mid*mid<x)
            {
                left=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return right;
     
    }
};
