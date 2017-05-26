/**
356[M].Line Reflection
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given set of points.
Example 1:
Given points = [[1,1],[-1,1]], return true.
Example 2:
Given points = [[1,1],[-1,-1]], return false.
Follow up:
Could you do better than O(n2)?
Hint:
1.     Find the smallest and largest x-value for all points.
2.     If there is a line then it should be at y = (minX + maxX) / 2.
3.     For each point, make sure that it has a reflected point in the opposite side.
**/
 
class Solution {
public:
	bool isReflected(vector<pair<int, int>>& points) {
            if(points.size()<2) return true;
            map<int, set<int> > mp;
            int min_x=INT_MAX, max_x=INT_MIN;
            for(int i=0;i<points.size();i++)
            {
                mp[points[i].first].insert(points[i].second);
                min_x=min(min_x, points[i].first;
                max_x=min(max_x, points[i].first;
            }
            double mid=(double)(min_x+max_x)/2;
            for(auto p:points)
            {
               int reflect=2*mid - p.first;
               if(mp.count(reflect)==0||mp[reflect].count(p.second)==0)
                        return false;          
            }
            return true;
   	}
};

