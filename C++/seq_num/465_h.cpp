/**
465[H]. Optimal Account Balance
A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for 10.ThenlaterChrisgaveAlice10.ThenlaterChrisgaveAlice5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].
Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.
Note:
1.     A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
2.     Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.
 
Example 1:
Input:
[[0,1,10], [2,0,5]]
 
Output:
2
 
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
 
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
 
Example 2:
Input:
[[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
 
Output:
1
 
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
 
Therefore, person #1 only need to give person #0 $4, and all debt is settled.
**/

class Solution {
public:   
    int minTransfers(vector<vector<int>>& transactions) {
        map<int, int> m;
        for(int i=0;i<transactions.size();i++)
        {
            m[transactions[i][0]]-=transactions[i][2];
            m[transactions[i][1]]+=transactions[i][2];
        }
        vector<int> account(m.size());
        int cnt=0;
        for(auto it:m)
        {
            account[cnt++]=it.second;
        }
        return dfs(account, 0, cnt, 0);
    }
    int dfs(vector<int> &account, int start, int n, int num)
    {
        int res=INT_MAX;
        while(start<n&&account[start]==0) start++;
        for(int i=start+1;i<n;i++)
        {
            if((account[start]>0&&account[i]<0)||(account[start]<0&&account[i]>0))
            {
                account[i]+=account[start];
                res=min(res, dfs(account, start+1, n, num+1));
                account[i]-=account[start];
            }
        }
        return res==INT_MAX?num:res;
    }
};
