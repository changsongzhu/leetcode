/**
533[M]. Lonely Pixel II
Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:
1.     Row R and column C both contain exactly N black pixels.
2.     For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
Example:
Input:                                        	
[['W', 'B', 'W', 'B', 'B', 'W'],	
 ['W', 'B', 'W', 'B', 'B', 'W'],	
 ['W', 'B', 'W', 'B', 'B', 'W'],	
 ['W', 'W', 'B', 'W', 'B', 'W']]
 
N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
    	0    1	2	3    4	5     	column index                                        	
0	[['W', 'B', 'W', 'B', 'B', 'W'],	
1     ['W', 'B', 'W', 'B', 'B', 'W'],	
2 	['W', 'B', 'W', 'B', 'B', 'W'],	
3 	['W', 'W', 'B', 'W', 'B', 'W']]	
row index
 
Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels.
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.
 
Note:
1.     The range of width and height of the input 2D array is [1,200].
**/
class Solution{
public:
    int findBlackPixel(vector<vector<char> >&picture, int N){
        if(picture.size()==0||picture[0].size()==0) return 0;
        int m=picture.size(), n=picture[0].size();
        unordered_map<int, set<int> > row;
        unordered_map<int, set<int> > col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(picture[i][j]=='B'){
                    row[i].insert(j);
                    col[j].insert(i);
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(picture[i][j]=='B'&&row[i].size()==N&&col[j].size()==N){
                     bool lonely=true;
                     for(auto r:col[j]){
                         if(row[r]!=row[i]){
                             lonely=false;
                             break;
                          }
                     }
                     res=(lonely==true?res+1:res);
                }
            }
         }
         return res;

    }
};


