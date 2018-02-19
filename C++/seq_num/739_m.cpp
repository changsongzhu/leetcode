/*
739. Daily Temperatures

Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].


*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        if(t.size()==0)return {};
        int m=t.size();
        vector<int> res(m, 0);
        int mx=t[m-1], mx_idx=m-1;
        for(int i=m-2;i>=0;i--){
            if(t[i]>mx){
                mx=t[i];
                mx_idx=i;
            }else if(t[i]==mx){
                mx_idx=i;
            }else{
                for(int j=i+1;j<=mx_idx;j++){
                    if(t[j]>t[i]){
                        res[i]=j-i;
                        break;
                    }
                }
            }
        }
        return res;
        
    }
};
