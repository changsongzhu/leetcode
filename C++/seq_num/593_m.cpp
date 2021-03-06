/**

593[M]. Valid Square
Given the coordinates of four points in 2D space, return whether the four points could construct a square.
The coordinate (x,y) of a point is represented by an integer array with two integers.
Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:
All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
**/

 
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int> dist;
        vector<vector<int> > points={p1, p2, p3, p4};
        for(int i=0;i<4;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                int x1=points[i][0],y1=points[i][1], x2=points[j][0], y2=points[j][1];
                int d=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                if(d==0) return false;
                dist[d]++;
            }
        }
        return dist.size()==2;
    }
};

