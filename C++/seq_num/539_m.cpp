/**
539[M]. Minimum Time Difference
 
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
**/
 
 
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(int i=0;i<timePoints.size();i++)
        {
            auto pos=timePoints[i].find_first_of(':');
            int val= stoi(timePoints[i].substr(0, pos))*60+stoi(timePoints[i].substr(pos+1));
            if(val<12*60) time.push_back(24*60+val);
            time_push_back(val);
        }
        sort(time.begin(), time.end());
        int res=INT_MAX;
        for(int i=1;i<time.size();i++)
        {
            res=min(res, time[i]-time[i-1]);
        }
        return res;
        
    }
};

