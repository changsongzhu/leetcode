/**
253[M]. Meeting Room II
 
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
**/

//MinHeap Solution
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals){
        if(intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start<b.start;});
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto a:intervals)
        {
            if(!pq.empty()&&a.start>=pq.top()) pq.pop();
            pq.push(a.end);
        }
        return pq.size();

    }
};


//Wrong Solution
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
       if(intervals.size()==0) return 0;
       int res=1;
       sort(intervals.begin(), intervals.end(), [](Interval &a, Interval&b){return a.start<=b.start||(a.start==b.start&&a.end>b.end);});
       int right=intervals[0].end;
       for(int i=1;i<intervals.size();i++)
       {
           if(intervals[i].start<right)
           {
              res++;
              right=min(right, intervals[i].end);
           }
       }
       return res;
   }
};

