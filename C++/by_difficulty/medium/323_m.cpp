/**
323[M] Number of Connected Components in an Undirected Graph

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
Example 1:
     0      	3
     |      	|
     1 --- 2	4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
Example 2:
     0       	4
     |       	|
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
**/
 
class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
       vector<int, vector<int> > g(n, vector<int>(0));
       vector<bool> visited(n, false);
       for(auto edge:edges)
       {
          g[edge.first].push_back(edge.second);
          g[edge.second].push_back(edge.first);
       }
       int res=0;
       for(int i=0;i<n;i++)
       {
          if(visited[i]==false)
          {
              dfs(g, visited, i);
              res++;
          }
       }
       return res;
    }
    void dfs(vector<int, vector<int> > &g, vector<bool> &visited, int start)
    {
       if(visited[start]) return;
       visited[start]==true;
       for(int i=0;i<g[start].size();i++)
          dfs(g, visited, g[start][i]);
    }
};

