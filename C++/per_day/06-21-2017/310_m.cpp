/**
310[M]. Minimum Height Trees
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
Example 1:
Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
        0
        |
        1
       / \
      2   3
return [1]
Example 2:
Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]
Note:
(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
**/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
       vector<int> res;
       int min_h=INT_MAX;
       vector<vector<int> > graph(n, vector<int>(0));
       for(auto e:edges)
       {
          graph[e.first].push_back(e.second);
          graph[e.second].push_back(e.first);
       }

       for(int i=0;i<n;i++)
       {
          vector<bool> visited(n, false);
          int h=dfs(graph, i, visited, min_h);
          if(min_h>h)
          {
              min_h=h;
              res.clear();
              res.push_back(i);
          }
          else if(min_h==h)
          {
              res.push_back(i);
          }
       }
       return res;
    }
    int dfs(vector<vector<int> > &graph, int idx, vector<bool> &visited, int min_h)
    {
       visited[idx]=true;
       int res=0;
       for(auto a:graph[idx])
       {
          if(visited[a]) continue;
          int h=dfs(graph, a, visited);
          if(h>min_h) return h;
          res=max(res, h);
       }
       return res+1;
    }
};
 

