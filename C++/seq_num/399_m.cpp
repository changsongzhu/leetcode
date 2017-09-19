/**
399[M]. Evaluate Division
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].
The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
According to the example above:
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
**/

ss Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double> > g;
        for(int i=0;i<equations.size();i++){
            g[equations[i].first][equations[i].second]=values[i];
            g[equations[i].first][equations[i].first]=1.0;
            g[equations[i].second][equations[i].first]= 1/values[i];
            g[equations[i].second][equations[i].second]= 1.0;
        }
        for(auto query:queries)
        {
           if(!g.count(query.first)||!g.count(query.second)) res.push_back(-1.0);
           else
           {
               queue<pair<string, double> > q;
               unordered_set<string> used({query.first});
               bool find=false;
               q.push({query.first, 1.0});
               while(!q.empty()&&!find)
               {
                   queue<pair<string, double> > next;
               
                   while(!q.empty()&&!find)
                   {
                       pair<string, double> t=q.front();q.pop();
                       if(t.first==query.second)
                       {
                           find=true;
                           res.push_back(t.second);
                           break;
                       }
                       else
                       {
                           for(auto a:g[t.first])
                           {
                               if(!used.count(a.first))
                               {
                                   used.insert(a.first);
                                   a.second*=t.second;
                                   next.push(a);
                               }
                           }
                       }
                   }
                   q=next;
               }
               if(!find) res.push_back(-1.0);
           }
        }
        return res;
    }
};
