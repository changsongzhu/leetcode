class Solution{
public:
    vector<string>  findLongestAssociation(vector<vector<string>  >&items)
    {
        map<string, vector<string> > graph;
        for(auto item:items)
        {
            graph[item[0]].push_back(item[1]);
            graph[item[1]].push_back(item[0]);
        }
        map<string, bool> visited;
        vector<string> res;
        int max_size=0;
        for(auto g:graph)
        {
            vector<string> path;
            dfs(graph, g.first, path, visited);
            if(path.size()>max_size)
            {
                max_size=path.size();
                sort(path.begin(), path.end());
                res=path;
            }
           else if(path.size()==max_size)
           {
               for(int i=0;i<max_size();i++)
               {
                    if(path[i]<res[i])
                    {
                         res=path;
                         break;
                    }
               }
           }
        }
        return res;
    }
    void dfs(map<string, vector<string> > &graph, string start, vector<string> &path, map<string, bool> &visited)
    {
        if(visited.count(start)) return;
        visited[start]=true;
        path.push_back(start);
        for(auto a:graph[start])
            dfs(graph, a, path, visited);
    }

};
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/

