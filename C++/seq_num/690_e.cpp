/**
690[E]. Employee Importance
You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.
For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.
Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.
Example 1:
Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.


Note:
One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.
**/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, int> importance;
        map<int, set<int> >sub;
        for(auto e:employees)
        {
            importance[e->id]=e->importance;
            for(auto s:e->subordinates)
            {
                sub[e->id].insert(s);
            }
        }
        return dfs(importance, sub, id);
        
    }
    int dfs(map<int, int>&imp, map<int, set<int> >&sub, int id)
    {
        if(sub.count(id)==0) return imp[id];
        int res=imp[id];
        for(auto s:sub[id])
            res+=dfs(imp, sub, s);
        return res;
    }
};

