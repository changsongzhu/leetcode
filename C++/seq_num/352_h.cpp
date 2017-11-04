/**
352[H]. Data Stream As Disjoint Intervals
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
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

//Similar solution for insert Interval (LC052)
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval cur(val, val);
        vector<Interval> res;
        bool insert=false;
        for(auto a:intervals)
        {
            if(insert==false)
            {
                if(cur.end+1<a.start)
                {
                    res.push_back(cur);
                    res.push_back(a);
                    insert=true;
                }
                else if(a.end+1<cur.start)
                {
                    res.push_back(a);
                }
                else
                {
                    cur.start=min(cur.start, a.start);
                    cur.end=max(cur.end, a.end);
                }
            }
            else
            {
                res.push_back(a);
            }
        }
        if(insert==false)
        {
            res.push_back(cur);
        }
        intervals=move(res);      
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
private:
    vector<Interval> intervals;
};


class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<Interval> res;
        Interval cur(val, val);
        int pos=0;
        for(auto a:intervals)
        {
            if(cur.end+1<a.start)
            {
                res.push_back(a);
            }
            else if(cur.start>a.end+1)
            {
                res.push_back(a);
                pos++;
            }
            else
            {
                cur.start=min(cur.start, a.start);
                cur.end  =max(cur.end, a.end);
            }
        }
        res.insert(res.begin()+pos, cur);
        intervals=res;
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
private:
    vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

