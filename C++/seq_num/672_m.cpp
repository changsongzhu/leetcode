/**
672[M]. Bulb Switcher II
There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.
Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:
Flip all the lights.
Flip lights with even numbers.
Flip lights with odd numbers.
Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
Example 1:
Input: n = 1, m = 1.
Output: 2
Explanation: Status can be: [on], [off]


Example 2:
Input: n = 2, m = 1.
Output: 3
Explanation: Status can be: [on, off], [off, on], [off, off]


Example 3:
Input: n = 3, m = 1.
Output: 4
Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].


Note: n and m both fit in range [0, 1000].
**/

class Solution {
public:
    int flipLights(int n, int m) {
        set<vector<bool>> ret;
        for (int k = 0; k < 16; ++k) {
            vector<bool> cur(n);
            int cnt = 0;
            for (int i = 0; i < 4; ++i) {
                if (k & (1 << i)) ++cnt;
            }
            if (cnt % 2 != m % 2) continue;
            if (m < cnt) continue;
            if (k & 1) {
                for (int i = 0; i < n; ++i) cur[i] = !cur[i];
            }
            if (k & 2) {
                for (int i = 1; i < n; i += 2) cur[i] = !cur[i];
                
            }
            if (k & 4) {
                for (int i = 0; i < n; i += 2) cur[i] = !cur[i];
            }
            if (k & 8) {
                for (int i = 0; i < n; i += 3) cur[i] = !cur[i];
                
            }
            ret.insert(cur);
        }
        return ret.size();
    }
};

