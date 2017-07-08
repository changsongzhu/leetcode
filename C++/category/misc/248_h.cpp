/**
248[H]. Strobogrammatic Number III
 
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
Note:
Because the range might be a large number, the low and high numbers are represented as string.
**/

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res=0;
        for(int i=low.size();i<=high.size();i++)
        {
            helper(low, high, "", i, res);
            helper(low, high, "0", i, res);
            helper(low, high, "1", i, res);
            helper(low, high, "8", i, res);
        }
        return res;
    }
    void helper(string low, string high, string path, int len, int &res)
    {
        if(path.size()> len) return;
        if(path.size()==len)
        {
            if(path.size()!=1&&path[0]=='0') return;
            if((path.size()==low.size()&&path.compare(low)<0)||path.size()==high.size()&&path.compare(high)>0) return;
            res++;
            return;
        }
        helper(low, high, "0"+path+"0", len, res);
        helper(low, high, "1"+path+"1", len, res);
        helper(low, high, "6"+path+"9", len, res);
        helper(low, high, "8"+path+"8", len, res);
        helper(low, high, "9"+path+"6", len, res);
    }
};

