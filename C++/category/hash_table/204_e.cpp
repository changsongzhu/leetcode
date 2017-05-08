/**
204[E]. Count Primers

Count the number of prime numbers less than a non-negative number, n.
**/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> res(n, true);
        res[0]=res[1]=false;
        res[2]=res[3]=true;
        for(int i=2;i<n;i++)
        {
            if(res[i]==true)
            {
                for(int j=2;j*i<n;j++)
                {
                    res[i*j]=false;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(res[i]==true)count++;
        }
        return count;
    }
};

