/**
514[H]. Freedom Trial
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.
Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string keyaligned at 12:00 direction and then by pressing the center button. 
At the stage of rotating the ring to spell the key character key[i]:
You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
Example:


Input: ring = "godding", key = "gd"
Output: 4
Explanation:
 For the first key character 'g', since it is already in place, we just need 1 step to spell this character.
 For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
 Also, we need 1 more step for spelling.
 So the final output is 4.
Note:
Length of both ring and key will be in range 1 to 100.
There are only lowercase letters in both strings and might be some duplicate characters in both strings.
It's guaranteed that string key could always be spelled by rotating the string ring.
**/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m=ring.size(), n=key.size();
        vector<vector<int> > v(26);
        vector<vector<int> > memo(m, vector<int> (n, 0));
        for(int i=0;i<m;i++) v[ring[i]-'a'].push_back(i);       
        return dfs(ring, key, 0, 0, v, memo);
    }
    int dfs(string ring, string key, int x, int y, vector<vector<int> > &v, vector<vector<int> > &memo)
    {
        if(y==key.size()) return 0;
        if(memo[x][y]) return memo[x][y];
        int res=INT_MAX, n=ring.size();
        for(auto k:v[key[y]-'a'])
        {
            int diff=abs(k-x);
            int step=min(diff, n-diff);
            res=min(res, step+dfs(ring, key, k, y+1, v, memo));
        }
        return memo[x][y]=res+1;
    }
};



