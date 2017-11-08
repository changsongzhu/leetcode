class Solution{
public:
    pair<int, int> overlapRange(vector<pair<int, int>  >&range)
    {
        pair<int, int> res;
        int mx_overlap=0;
        sort(ranges.begin(), ranges.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first<b.first||(a.first==b.first&&a.second<b.second);

     });

     for(int i=0;i<ranges.size();i++)
     {
         int cnt=1;
         int start=ranges[i].first, end=ranges[i].second;
         for(int j=i+1;j<ranges.size();j++)
         {
             if(ranges[j].first>end) break;
             start=max(start, ranges[j].first);
             end=min(end, ranges[j].second;
             cnt++;
         }
         if(cnt>mx_overlap)
         {
             mx_overlap=cnt;
             res={start, end};
         }
     }
     return res;
    }
};
/*
Time Complexity: O(N2)
Space Complexity: O(1)

if just need to return the count, we can use the dp[j] to do it

sort(ranges.begin(), ranges.end(), [](pair<int, int> &a, pair<int, int> &b){return a.first<b.first;});
 int res=0;
for(int j=0;j<m;j++)
{
    dp[j]=1;
    for(int i=0;i<j;i++)
    {
        if(ranges[j].first>ranges[i].second)
           dp[j]=max(dp[j], dp[i]+1);
    }
    res=max(res, dp[j]);
}
*/

