/*Given some points and a point originin two dimensional space, findkpoints out of the some points which are nearest to origin.
Return these points sorted by distance, if they are same with distance, sorted by x-axis, otherwise sorted by y-axis.
Example
Given points =[[4,6],[4,7],[4,4],[2,5],[1,1]], origin =[0, 0], k =3
return[[1,1],[2,5],[4,4]]
*/
class Solution{
public:
    vector<pair<int, int> > kClosestPoints(vector<pair<int, int> > &points, pair<int, int> &origin, int k)
    {
        vector<pair<int, int> > res(k);
        global_origin=origin;
        struct comp{
            bool operator()(pair<int, int> p1, pair<int, int> p2)
            {
                int x1=p1.first-gloabl_origin.first, y1=p1.second-gloabl_origin.second;
                int x2=p2.first-gloabl_origin.first, y2=p2.second-gloabl_origin.second;
                int d1=x1*x1+y1*y1;
                int d2=x2*x2+y2*y2;
                return d1<d2||(d1==d2&&x1<x1)||(d1==d2&&x1==x2&&y1<y2);
            }
        };
       priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
       for(auto p:points)
       {
           pq.push(p);
           if(pq.size()>k) pq.pop();
       }
       int i=0;
       while(!pq.empty())
       {
           res[k-1-i]=pq.top();
           pq.pop();
           i++;
       }
       return res;
    }
private:
    pair<int, int> global_origin;
};

