/**
364[M]. Nested List Weight Sum II
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 
Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
 
Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
 
Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17) 
**/
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
       if(nestedList.size()==0) return 0;
       vector<int> path;
       for(auto ni:nestedList)
           helper(ni, 0, path);
       int res=0;
       for(int i=0;i<path.size();i++)
       {
          res+=path[i]*(path.size()-i);
       }
       return res;
    }
    void helper(NestedInteger ni, int level, vector<int> &v)
    {
        if(v.size()<level+1) v.push_back(0);
        if(ni.isInteger())
        {
            v[level]+=ni.getInteger();
        }
        else
        {
           for(auto n:ni.getList())
              helper(n, level+1, v);
        }
    }
};

