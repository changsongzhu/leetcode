/**
52[H]. N-Queens II
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
**/

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> pos(n, -1);
        int res=0;
        helper(res, pos, n, 0);
        return res;
    }
    void helper(int &res, vector<int> &pos, int n, int row)
    {
        if(row==n)
        {
            res++;return;
        }
        for(int i=0;i<n;i++)
        {
            pos[row]=i;
            if(isValid(pos, row, i))
                helper(res, pos, n, row+1);
            pos[row]=-1;
        }
    }
    bool isValid(vector<int> &pos, int row, int col)
    {
        for(int i=0;i<row;i++)
        {
             if(col==pos[i]||abs(row-i)==abs(pos[i]-col)) return false;
        }
        return true;
    }
};

