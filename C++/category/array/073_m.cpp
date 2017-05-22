/**
73[M]. Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
**/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return;
        int m=matrix.size(), n=matrix[0].size();
        bool first_row=false, first_col=false;
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                first_row=true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                first_col=true;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0||matrix[i][0]==0)
                    matrix[i][j]=0;
            }
        }
        if(first_row==true)
            for(int i=0;i<n;i++) matrix[0][i]=0;
        if(first_col==true)
            for(int i=0;i<m;i++) matrix[i][0]=0;
    }
};
