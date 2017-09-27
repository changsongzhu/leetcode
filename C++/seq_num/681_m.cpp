/**
681[M]. Next Closest Time
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
Example 1:
Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.


Example 2:
Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
**/

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> digits;
        set<int> times;
        int cur_time=0;
        digits.push_back(time[0]-'0');
        digits.push_back(time[1]-'0');
        digits.push_back(time[3]-'0');
        digits.push_back(time[4]-'0');
        cur_time=(digits[0]*10+digits[1])*60+digits[2]*10+digits[3];
        vector<int> path;
        helper(times, digits, path);
        int res=0;
        int gap=INT_MAX;
        for(auto a:times)
        {
            int tmp=0;
            if(a>cur_time)
            {
                tmp=a-cur_time;
            }
            else if(a==cur_time)
            {
                tmp=24*60;
            }
            else
            {
                tmp=24*60-cur_time+a;
            }
            if(gap>tmp)
            {
                res=a;
                gap=tmp;
            }
        }
        return to_string((res/60)/10)+to_string((res/60)%10)+":"+to_string((res%60)/10)+to_string((res%60)%10);
        
    }
    void helper(set<int> &res, vector<int>&digits, vector<int> &path)
    {
        if(path.size()==4&&path[0]<=2&&path[2]<=5)
        {
            int val=(path[0]*10+path[1])*60+path[2]*10+path[3];
            if(val<24*60) res.insert(val);
            return;
        }
        if(path.size()>4) return;
        for(int i=0;i<digits.size();i++)
        {
            path.push_back(digits[i]);
            helper(res, digits, path);
            path.pop_back();
        }
    }
};

