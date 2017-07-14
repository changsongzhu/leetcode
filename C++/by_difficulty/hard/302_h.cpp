/**
302[H]. Smallest Rectangle Enclosing Black Pixels
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
For example, given the following image:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
 
Return 6.
**/

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m=image.size(), n=image[0].size();
        int left=y, right=y, up=x, down=x;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(image[i][j]=='0') continue;
                left=min(j, left);
                right=max(j, right);
                up=min(i, up);
                down=max(i, down);
            }
        }
        return (right-left+1)*(down-up+1);
   }
};

