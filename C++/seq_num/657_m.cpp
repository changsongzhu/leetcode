/**
657[E] Judge Route Circle
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
Example 1:
Input: "UD"
Output: true


Example 2:
Input: "LL"
Output: false
**/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(int i=0;i<moves.size();i++)
        {
            char M=moves[i];
            x=((M=='R')?(x+1):((M=='L')?(x-1):x));
            y=((M=='U')?(y+1):((M=='D')?(y-1):y));
            
        }
        if(x==0&&y==0) return true;
        else return false;       
    }
};

