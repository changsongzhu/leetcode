/**
48[M]. Rotate Image
 
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
**/

/*

clockwise rotate

1 2
3 4

--> up<-->down  3 4
                1 2

--> diagnosal   3 1
                4 2

anti-clockwise rotate

1 2
3 4
--> up<-->down 3 4
               1 2

--> anti-diagnosal  2 4
                    1 3

*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()<2|| matrix.size()!=matrix[0].size()) return;
        int r=matrix.size(),c=matrix[0].size();
        int up=0, down=matrix.size()-1;
        while(up<down)
        {
            for(int i=0;i<c;i++)
                swap(matrix[up][i],matrix[down][i]);
            up++;
            down--;
        }
        for(int i=0;i<r;i++)
        {
           for(int j=0;j<i;j++)
           {
               swap(matrix[i][j], matrix[j][i]);
           }
        }
    }
};


//Anti-clockwise
class Solution {
public:
    void rotate_2(vector<vector<int> >&m)
    {
        if(m.size()<2||m.size()!=m[0].size()) return;
        int r=m.size(), c=m.size();
        int up=0,down=r-1;
        while(up<down)
        {
            for(int i=0;i<c;i++
                swap(m[up][i], m[down][i]);
            up++;
            down--;
        }
        for(int i=0;i<r;i++)
        {
            for(int j=r-i, k=1;j<c;j++, k++)
                swap(m[i][j], m[i-k][j-k]);
        }
    }
};
