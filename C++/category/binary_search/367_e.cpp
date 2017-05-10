/**

367[M]. Valid Perfect Square
 
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.
Example 1:
Input: 16 Returns: True
Example 2:
Input: 14 Returns: False 

**/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long left=1, right=num/2+1;
        long mid=0;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(mid*mid==num)
            {
                return true;
            }
            else if(mid*mid<num)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return false;
    }
};
