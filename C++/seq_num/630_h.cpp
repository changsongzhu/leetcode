/**
630[M]. Course Schedule III
There are n different online courses numbered from 1 to n. Each course has some duration(course length)t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.
Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.
Example:
Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation:
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day.
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day.
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
Note:
The integer 1 <= d, t, n <= 10,000.
You can't take two courses simultaneously.
**/

class Solution {
public:
    int scheduleCourse(vector<vector<int> >&courses){
         sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){return a.back()<b.back();});
         priority_queue<int>  pq;
         int now=0;
         for(int i=0;i<courses.size();i++)
         {
             now+=courses[i][0];
             pq.push(courses[i][0]);
             if(now>courses[i][1])
             {
                  now-=pq.top();
                  pq.pop();
             }
         }
         return pq.size();
    }
};


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // sort courses by the end date
        sort(courses.begin(),courses.end(),
            [](vector<int> a, vector<int> b){return a.back()<b.back();});
            
        multiset<int> cls; // store lengths of each course we take (could be duplicates!)
        int cursum=0;
        
        for (int i=0; i<courses.size(); i++) {
            
            // if we have enough time, we will take this course
            if (cursum+courses[i].front()<=courses[i].back()) {
                cls.insert(courses[i].front());
                cursum+=courses[i].front();
            } else if (*cls.rbegin()>courses[i].front()) {
                // if we don't have enough time, we switch out a longer course
                cursum+=courses[i].front()-*cls.rbegin();
                cls.erase(--cls.end());
                cls.insert(courses[i].front());
            } // if we don't have enough time for course[i], 
              //and it's longer than any courses taken, then we ignore it
        }
        
        return cls.size();
    }
};

