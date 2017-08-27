/**
668[H*]. K-th Largest Number in Multiplation Table
Nearly every one have used the Multiplication Table. But could you find out the k-th largest number quickly from the multiplication table?
Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th largest number in this table.
Example 1:
Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th largest number is 3 (1, 2, 2, 3, 3).


Example 2:
Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th largest number is 6 (1, 2, 2, 3, 4, 6).


Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]
**/

//TLE Solution
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> index(m, 0);
        int res=0;
        for(int i=0;i<k;i++)
        {
            int idx=-1;
            int mn=INT_MAX;
            for(int j=0;j<m;j++)
            {
                if(index[j]==n) continue;
                mn=min(mn, (j+1)*(index[j]+1));
            }
            for(int j=0;j<m;j++)
            {
                if(index[j]!=n&&mn==(j+1)*(index[j]+1))
                {
                    index[j]++;
                    break;
                }
            }
            res=mn;
        }
        return res;
        
    }
};
//TLE Solution
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> index(m, 0);
        int res=0;
        for(int i=0;i<k;i++)
        {
            int idx=-1;
            int mn=INT_MAX;
            int mn_idx=-1;
            for(int j=0;j<m;j++)
            {
                if(index[j]==n) continue;
                if((j+1)*(index[j]+1)<mn)
                {
                    mn_idx=j;
                    mn=(j+1)*(index[j]+1);
                }
                
            }
            index[mn_idx]++;
            res=mn;
        }
        return res;
        
    }
};


class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low != high) {
            int mid = (low + high) / 2;
            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                cnt += min(mid / i, n);
            }
            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
        
    }
};
