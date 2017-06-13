/**
 
378[M]. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
 
return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
**/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==1) return matrix[0][0];
        int n=matrix.size();
        vector<int> idx(n, 0);
        int cnt=0, res=0;
        while(cnt<k)
        {
            int mn=INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(idx[i]!=n)
                    mn=min(matrix[i][idx[i]], mn);
            }
            for(int i=0;i<n;i++)
            {
                if(idx[i]!=n&&mn==matrix[i][idx[i]])
                {
                    idx[i]++;
                    break;
                }
            }
            res=mn;
            cnt++;
        }
        return res;
    }
};

