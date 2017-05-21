/**56[M]. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
    vector<Interval> merge(vector<Interval>& intervals) {
         vector<Interval> res;
         if(intervals.size()==0) return res;
         sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start<b.start;});
         int start=intervals[0].start;
         int prev_end=intervals[0].end;
         for(int i=1;i<intervals.size();i++)
         {
             if(intervals[i].start<=prev_end)
             {
                 prev_end=max(prev_end, intervals[i].end);
             }
             else
             {
                 res.push_back(Interval(start, prev_end));
                 start=intervals[i].start;
                 prev_end=intervals[i].end;
             }
         }
         res.push_back(Interval(start, prev_end));
         return res;
    }
};;
