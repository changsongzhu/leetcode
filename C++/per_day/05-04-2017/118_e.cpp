/**
118[E]. Pascal’s Triangle
 
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[  	
    [1], 	
   [1,1],	
  [1,2,1],  
 [1,3,3,1], 
[1,4,6,4,1]
]


**/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(numsRows==0) return res;
        for(int i=0;i<numRows;i++)
        {
            vector<int> tmp;
            if(i==0)
            {
                tmp.push_back(1);
            }
            else
	    {
                for(int j=0;j<=i;j++)
                {
                    if(j==0 || j==i) tmp.push_back(1);
                    else tmp.push_back(res[i-1][j]+res[i-1][j-1]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

