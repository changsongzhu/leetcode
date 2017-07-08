/**
403[H]. Frog Jump
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.
If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.
Note:
The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:
[0,1,3,5,6,8,12,17]
 
There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.
 
Return true. The frog can jump to the last stone by jumping
1 unit to the 2nd stone, then 2 units to the 3rd stone, then
2 units to the 4th stone, then 3 units to the 6th stone,
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:
[0,1,2,3,4,8,9,11]
 
Return false. There is no way to jump to the last stone as
the gap between the 5th and 6th stone is too large.
**/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        map<int, bool> m;
        return dfs(m, 0, 0, stones);
    }
    bool dfs(map<int, bool> &m, int pos, int jump, vector<int> &stones)
    {
        int n=stones.size(), key=pos|jump<<16;
        if(pos==n-1) return m[key]=true;
        if(m.count(key)) return m[key];
        for(int i=pos+1;i<n;i++)
        {
            int dist=stones[i]-stones[pos];
            if(dist<jump-1) continue;
            if(dist>jump+1) return m[key]=false;
            if(dfs(m, i, dist, stones)) return m[key]=true;
        }
        return m[key]=false;
    }
};


/*TLE Solution*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size()==0) return false;
        map<int, int> m;
        for(auto stone:stones)m[stone]++;
        return dfs(m, INT_MAX, stones[0], stones[stones.size()-1]);
    }
    bool dfs(map<int, int> &m, int prev_step, int cur_pos, int last )
    {
        if(cur_pos==last) return true;
        if(m.count(cur_pos)==0||cur_pos>last) return false;
        if(prev_step<=0) return false;
        
        if(prev_step==INT_MAX)
        {
            return dfs(m, 1, cur_pos+1, last);
        }
        else
        {
            return dfs(m, prev_step-1, cur_pos+prev_step-1, last)||
                   dfs(m, prev_step, cur_pos+prev_step, last)||
                   dfs(m, prev_step+1, cur_pos+prev_step+1, last);
        }
    }
};


