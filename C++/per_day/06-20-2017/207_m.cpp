/**
207[M]. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
**/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
       vector<vector<int> > graph(numCourses, vector<int> (0));
       vector<int> visited(numCourses, 0);
       for(auto a:prerequisites)
           graph[a.second].push_back(a.first);
       for(int i=0;i<numCourses;i++)
          if(!helper(graph, visited, i)) return false;
       return true;
    }
    bool helper(vector<vector<int> > &graph, vector<int> &visited, int i)
    {
       if(visited[i]==-1) return false;
       if(visited[i]==1) return true;
       visited[i]=-1;
       for(auto a:graph[i])
           if(!helper(graph, visited, a)) return false;
       visited[i]=1;
       return true;
    }
};

