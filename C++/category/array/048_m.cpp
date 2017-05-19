/**
48[M]. Rotate Image
 
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
**/
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
