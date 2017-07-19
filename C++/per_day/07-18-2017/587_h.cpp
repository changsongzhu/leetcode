/**

587[H]. Erect the Fence
There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.
Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:



Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 


Note:
All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.
**/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int orientation(Point p, Point q, Point r){
        return (q.y - p.y) * (r.x - q.x) -(q.x - p.x) * (r.y - q.y);     
    }
    bool inBetween(Point p, Point i, Point q) {
        bool a = i.x >= p.x && i.x <= q.x || i.x <= p.x && i.x >= q.x;
        bool b = i.y >= p.y && i.y <= q.y || i.y <= p.y && i.y >= q.y;
        return a && b;
    }
    static bool equ(Point &p1, Point &p2) { return p1.x == p2.x && p1.y == p2.y; }
    static bool cmp(Point &p1, Point &p2) {return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);}
    
    vector<Point> outerTrees(vector<Point>& points) {
        int n=points.size();
        vector<Point> hull;

        int l = 0;
        for (int i = 1; i < n; i++)
            if (points[i].x < points[l].x)
               l = i;
        
        int p = l, q;
        do
        {
            hull.push_back(points[p]);
            q = (p+1)%n; 
            for (int i = 0; i < n; i++)
            {
               if (orientation(points[p], points[i], points[q])<0)
                   q = i;
            }
            for (int i = 0; i < n; i++)
            {
               if(i!=p&&i!=q&&inBetween(points[p], points[i], points[q])&&orientation(points[p], points[i], points[q])==0)
                   hull.push_back(points[i]);
            }
            hull.push_back(points[q]);

            p = q;
        } while (p != l);
        
        sort(hull.begin(), hull.end(), cmp);
        hull.erase(unique(hull.begin(), hull.end(), equ), hull.end());
        return hull;
    }
};
