/**
276[E]. Paint Fence
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
Note:
n and k are non-negative integers.
**/

class Solution
{
public:
    int paintFence( int n, int k)
        if(n==0) return 0;
        int res=k;
        for(int i=1;i<n;i++)
            res=res*(k-1);
        return res;
    }
};
