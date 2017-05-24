/**
531[M]. Lonely Pixel I
 
Given a picture consisting of black and white pixels, find the number of black lonely pixels.
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.
Example:
Input:
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]
 
Output: 3
Explanation: All the three 'B's are black lonely pixels.
 
Note:
1.     The range of width and height of the input 2D array is [1,500].
**/


class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.size()==0||pciture[0].size()==0) return 0;
        int m=picture.size(), n=picture[0].size();
        vector<int> col(n, 0);
        vector<int> row(m, 0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(picture[i][j]=='B')
                   row[i]++;
            }
        }
        for(int j=0;j<n;i++)
        {
            for(int i=0;i<m;i++)
            {
                if(picture[i][j]=='B')
                   col[j]++;
            }
        }
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(picture[i][j]=='B'&&row[m]==1&&col[n]==1)
                    res++;
            }
        }
        return res;
   }
};

