/**
311[M].Sparse Matrix Multiplication
Given two sparse matrices A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.
Example:
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]
 
B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]
 
 
 	|  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
 	             | 0 0 1 |
**/

//Refined Solution
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> >  res(A.size(), vector<int>(B[0].size(), 0));
        for(int i=0;i<A.size();i++)
        {
            for(int k=0;k<A[i].size();k++)
            {
                if(A[i][k])
                {
                    for(int j=0;j<B[0].size();j++)
                    {
                        if(B[k][j])
                        {
                            res[i][j]+=A[i][k]*B[k][j];
                        }
                    }
                }
            }
        }
        return res;
    }
};

 
 class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<int, vector<int> > row_mp;
        map<int, set<int> > col_mp;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[i].size();j++)
                row_mp[i].push_back(j);
        }
        for(int j=0;j<B[0].size();j++)
        {
            for(int i=0;i<B.size();i++)
                col_mp[j].insert(i);
        }
        vector<vector<int> > res(A.size(), vector<int>(A[0].size(), 0));
        for(auto a:row_mp)
        {
            int i=a.first;
            int sum=0;
            if(col_mp.count(i)==0) continue;
            else
            {
                for(b:a.second)
                {
                    if(col_mp[i].count(b)!=0)
                        sum+=A[i][b]*B[b][i];
                }
                res[i][b]=sum;
            }
        }
        return res;
    }
};

