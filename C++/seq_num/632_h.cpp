/**
632[H] Smallest Range
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.
We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
**/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vi;
        struct comp{
            bool operator()(pair<vi, vi> p1, pair<vi, vi> p2)
            {
                return *p1.first>*p2.first;
            }
        };
        priority_queue<pair<vi, vi>, vector<pair<vi, vi> >, comp> pq;
        int mn=INT_MAX, mx=INT_MIN;
        for(auto &num:nums)
        {
            mn=min(mn, num[0]);
            mx=max(mx, num[0]);
            pq.push({num.begin(), num.end()});
        }
        vector<int> res={mn, mx};
        while(true)
        {
            auto p=pq.top();pq.pop();
            ++p.first;
            if(p.first==p.second) break;
            pq.push(p);
            mn=*pq.top().first;
            mx=max(mx, *p.first);
            if(mx-mn<res[1]-res[0])
                res={mn, mx};
        }
        return res;
    }
};

