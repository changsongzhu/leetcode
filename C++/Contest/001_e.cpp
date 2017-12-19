#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <typeinfo>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Point{
    int x;
    int y;
    Point(int a, int b):x(a), y(b){}
};

class Solution{
public:
    vector<Point > kCloestPoint(vector<Point> &points, Point &origin, int k)
    {
        vector<Point> res;
        map<int, set<pair<int, int> > > m;
        int cnt=0;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i].x, y=points[i].y;
            int dist=(x-origin.x)*(x-origin.x)+(y-origin.y)*(y-origin.y);
            m[dist].insert(make_pair(x, y));
        }
       for(map<int, set<pair<int, int> >::iterator it=m.begin();it!=m.end();it++)
       {
            if(cnt==k) break;
            for(auto b:it->second)
            {
                res.push_back(Point(b.first, b.second);
                cnt++;
                if(cnt==k) break;
            }
       } 
       return res;
    }
};


int main(void)
{
    Solution solution;
    vector<Point> points;
    nums.push_back(Point(4, 6));
    nums.push_back(Point(4, 7));
    nums.push_back(Point(4, 4));
    nums.push_back(Point(2, 5));
    nums.push_back(Point(1, 1));
    Point origin(0, 0);
    vector<Point> res=solution.kCloestPoint(points, origin, 3);
    cout<<"Result:"<<endl;
    for(auto a: res)
        cout<<a.x<<a.y<<endl;
    cout<<"Finish"<<endl; 

    return 0;
}
