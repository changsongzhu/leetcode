/**
552[H]. Student Attendance Record II
Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.
A student attendance record is a string that only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
Example 1:
Input: n = 2
Output: 8
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times.
Note: The value of n won't exceed 100,000.
**/
class Solution {
public:
    int checkRecord(int n) {
        int res=0;
        vector<long long> P(n+1), PorL(n+1);
        P[0]=1, PorL[0]=1, PorL[1]=2;
        for(int i=1;i<=n;i++)
        {
            P[i]=PorL[i-1];
            if(i>1) PorL[i]=(P[i]+P[i-1]+P[i-2])%1000000007;
        }
        res=PorL[n];
        for(int i=0;i<n;i++)
        {
            long long t=PorL[i]*PorL[n-1-i]%1000000007;
            res=(res+t)%1000000007;
        }
        return res;
    }
};

//TLE Solution
class Solution {
public:
    int checkRecord(int n) {
        int res=0;
        string path="";
        helper(path, n, 0, res, false);
        return res;
    }
    void helper(string path, int n, int start, int &res, bool absent)
    {
        if(n==start)
        {
            res=(res+1)%1000000007;
            return;
        }
        if(absent==false)    helper(path+"A", n, start+1, res, true);
        if(path.size()<2||!(path[path.size()-2]=='L'&&path[path.size()-1]=='L')) helper(path+"L", n, start+1, res, absent);
        if(isValid(path+"P")) helper(path+"P", n, start+1, res, absent);
    }

    bool isValid(string s) {
        int absent_cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A')
            {
                absent_cnt++;
                if(absent_cnt>1) return false;
            }
            else if(s[i]=='L')
            {
                if(i>=2&&s[i-1]=='L'&&s[i-2]=='L') return false;
            }
        }
        return true;

    }
};
