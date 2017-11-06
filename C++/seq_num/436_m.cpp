/**
436[M]. Find Right Interval
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.
Note:
You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
Example 1:
Input: [ [1,2] ]
 
Output: [-1]
 
Explanation: There is only one interval in the collection, so it outputs -1.
Example 2:
Input: [ [3,4], [2,3], [1,2] ]
 
Output: [-1, 0, 1]
 
Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
Example 3:
Input: [ [1,4], [2,3], [3,4] ]
 
Output: [-1, 2, -1]
 
Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
**/

 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>&intervals){
        struct comp{
            bool operator()(pair<int, int> &a, pair<int, int>&b){
                return a.first>b.first;}
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq_start;
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq_end;
        for(int i=0;i<intervals.size();i++)
        {
            pq_start.push({intervals[i].start, i});
            pq_end.push({intervals[i].end, i});
        }
        vector<int> res(intervals.size(), -1);
        while(!pq_end.empty())
        {
            auto p=pq_end.top();pq_end.pop();
            while(!pq_start.empty()&&(p.first>pq_start.top().first||p.second==pq_start.top().second)) pq_start.pop();
            if(!pq_start.empty()) res[p.second]=pq_start.top().second;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> mp;
        int mx=INT_MIN;
        vector<int> res(intervals.size(), -1);
        for(int i=0;i<intervals.size();i++)
        {
            mx=max(mx, intervals[i].start);
            mp[intervals[i].start]=i;
        }
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i].end<=mx)
            {
                for(int j=intervals[i].end;j<=mx;j++)
                {
                    if(mp.find(j)!=mp.end())
                    {
                        res[i]=mp[j];
                        break;
                    }
                }
            }
        }
        return res;
    }
};

