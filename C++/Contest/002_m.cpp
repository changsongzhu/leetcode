#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
class Solution{
public:
    vector<string>  findLongestAssociation(vector<vector<string>  >&items)
    {
        map<string, vector<string> > graph;
        for(auto item: items)
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
                res=path;
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
*/


/*
class Solution{
public:
    int bstDistance( vector<int> &nums, int n1,  int n2)
    {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        TreeNode *root=createBST(nums, 0, nums.size()-1);
        TreeNode *lca=findLCA(root, n1, n2);
        if(lca==NULL) return 0;
         int l1=findLevel(root, n1, 1);
         int l2=findLevel(root, n2, 1);
         if(l1==0||l2==0) return 0;
         return l1+l2-2*findLevel(root, lca->val, 1);
    }

    TreeNode *createBST(vector<int> &nums, int start, int end)
     {
          if(start>end) return NULL;
          TreeNode *node=new TreeNode(nums[start+(end-start)/2]);
          node->left=createBST(nums, start, start+(end-start)/2-1);
          node->right=createBST(nums, start+(end-start)/2+1, end);       
      }
      TreeNode* findLCA(TreeNode *root, int val1, int val2)
      {
          if(root==NULL) return NULL;
          if(root->val>val1&&root->val>val2) return findLCA(root->left, val1, val2);
          if(root->val<val1&&root->val<val2) return findLCA(root->right, val1, val2);
          return root;
      }
      int findLevel(TreeNode* root, int val, int level)
      {
          if(root==NULL) return 0;
          if(root->val==val) return level;
          int downlevel=0;
          if(root->val>val)
              downlevel=findLevel(root->left, val, level+1);
          else
              downlevel=findLevel(root->right, val, level+1);
          return downlevel!=0?downlevel:0;
      }
};
*/
/**
class Solution{
public:
    vector<vector<string> > menu(vector<vector<string>  > &menu, vector<vector<string>  > &person)
    {
        map<string, vector<string>  > m; // Dish type
        for(int i=0;i<menu.size();i++)
        {
            m[menu[i][1]].push_back(menu[i][0]);
        }
        vector<vector<string> > res;
        for(int i=0;i<person.size();i++)
        {
            string name=person[i][0];
            if(person[i][1]=="*")
            {
                for(auto a:m)
                {
                    for(auto b:a.second)
                    	res.push_back({name, b});
                }
            }
           else
           {
                for(auto a:m[person[i][1]])
                {
                    cout<<"name:"<<name<<"dish"<<a<<endl;
                    res.push_back({name, a});
                }
           }
        }
        return res;
    }
};
**/
/**
struct Point{
    int x;
    int y;
    Point(int a, int b):x(a), y(b){}
};


class Solution{
public:
    vector<pair<int, int> > kClosestPoints(vector<pair<int, int> > &points, pair<int, int> &origin, int k)
    {
        vector<pair<int, int> > res(k);
        struct comp{
            bool operator()(pair<int, int> p1, pair<int, int> p2)
            {
                int x1=p1.first, y1=p1.second;
                int x2=p2.first, y2=p2.second;
                int d1=x1*x1+y1*y1;
                int d2=x2*x2+y2*y2;
                return d1<d2||(d1==d2&&x1<x1)||(d1==d2&&x1==x2&&y1<y2);
            }
        };
       priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
       for(auto p:points)
       {
           pq.push(p);
           if(pq.size()>k) pq.pop();
       }
       int i=0;
       while(!pq.empty())
       {
           res[k-1-i]=pq.top();
           pq.pop();
           i++;
       }
       return res; 
    }
};
**/
class Solution{
public:
    int minChange(vector<int> &changes, int target)
    {
         vector<int> dp(target+1, target+1);
         map<int, int> m;
         for(auto c:changes) m[c]++;
         dp[0]=0;
         for(int i=1;i<=target;i++)
         {
             if(m.count(i)!=0) dp[i]=1;
             else
             {
                 for(int j=0;j<i;j++)
                 {
                     dp[i]=min(dp[i], dp[j]+dp[i-j]);
                 }
             }
         }
         return dp[target];
    }
};

//Greedy Method
class Solution2{
public:
    int minChange(vector<int> changes, int target)
    {
        sort(changes.rbegin(), changes.rend());
        int sum=0;
            int cnt=0;
            for(int j=0;j<changes.size();j++)
            {
                if(sum+changes[j]>target) continue;
                while(sum+changes[j]<=target)
                {
                    sum+=changes[j];
                    cnt++;
                    if(sum==target) break;//res=min(res, cnt);
                }
           } 
       return cnt;
    }
};

/**class Solution
{
public:
    int maxObjects(vector<vector<int> > &objects, vector<int> box)
    {
         int res=0;
        dfs(objects, 0, box[0], box[1], box[2], 0, res);
        return res;
    }

    void dfs(vector<vector<int> >&objects, int index,  int x, int y, int z, int cnt, int &res)
    {
        if(index>=objects.size()) return;
        if(x==0||y==0||z==0) return;
        for(int i=index;i<objects.size();i++)
        {
            int a=objects[i][0], b=objects[i][1], c=objects[i][2];
            if(a>x||b>y||c>z) continue;
            res=max(cnt+1, res);
            dfs(objects, i+1,x-a, y-b, z-c, cnt+1, res);
        }
    }

};
**/
/*
class Solution2{
public:
    int kMaxProduct(vector<int> &nums, int k){
       if(k>nums.size()) return -1;
       int res=1;
       sort(nums.begin(), nums.end());
       for(auto n:nums) cout<<n<<" ";
       cout<<endl;
       int left=0, right=nums.size()-1;
       while(k>0)
       {
            if(k>=2)
            {
                 if(nums[left]*nums[left+1] < nums[right]*nums[right-1])
                 {
                     res*=nums[right--];
                     k--;
                 }
                 else
                {
                    res*=(nums[left]*nums[left+1]);
                    left+=2;
                    k-=2;
                }
            }
            else
            {
                res*=nums[right--];
                k--;
            }      
       }
      return res;  
   }
};
**/



int main(void)
{
    Solution solution;
    Solution2 solution2;
/*    vector<vector<string > > items={{"A", "B"}, {"B", "C"}, {"D", "E"}, {"E", "F"}, {"G", "D"}};
    vector<string> res=solution.findLongestAssociation(items);
    for(auto s:res)
       cout<<s<<endl; 
*/
/*    vector<int> nums={1,3,5, 7, 9, 10, 12, 4};
    int res=solution.bstDistance(nums, 3, 5);
    cout<<"Result:"<<res<<endl;
*/
/**    vector<vector<string> > menu ={{"A", "China"}, {"B", "Japan"}, {"C", "China"}, {"D", "USA"}};
    vector<vector<string> > person={{"John", "China"}, {"Tom", "*"}};
    vector<vector<string> > res=solution.menu(menu, person);
    for(auto r:res)
       cout<<r[0]<<":"<<r[1]<<endl;
**/ 
/**    vector<pair<int, int> > points={{1,3}, {2, 3}, {4, 5}, {3, 5}, {6, 7}};
    pair<int, int> origin={0, 0};
    vector<pair<int, int> > res=solution.kClosestPoints(points, origin, 3);
    for(auto p:res)
        cout<<p.first<<":"<<p.second<<endl;
**/
    vector<int>  changes={1, 3, 7};
    int res=solution.minChange(changes, 25);
    cout<<"Mini Change:"<<res<<endl;
    res=solution2.minChange(changes, 25);
    cout<<"Mini Change2:"<<res<<endl;

    /*vector<vector<int> > nums={{1, 2, 4}, {2, 3,4}, {4, 2, 1}};
    vector<int> box={8, 8, 8};
    int res=solution.maxObjects(nums, box);
    cout<<"Max objects: "<< res<<endl;
**/
/**
    int k=0;
    while(k<1)
    {
        vector<int>  res;
        for(int i=5;i<10;i++)
        {
            for(int j=0;j<i;j++)
            {
                int num=rand()%20;
                res.push_back(num);
                num=rand()%20;
                res.push_back(-num);
            }
            int mx=solution2.kMaxProduct(res, 3);
            cout<<"Res="<< mx<<endl<<endl<<endl;
        }
        k++;
        
    }
**/    
    return 0;
}
