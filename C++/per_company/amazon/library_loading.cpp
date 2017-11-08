/**
       A
    B   C
D   E     F
运行A需要加载B，运行B需要加载D和E。编写程序返回运行A所需要加载的包。
图
**/

public List<String> findAllPrerequisite(Map<String, List<String>>, String target)
Queue<String> queue = new Queue<>();
BFS…

class Solution{
public:
    vector<string> findAllPrerequisite(map<string, vector<string> > dependence, string target)
    {
        vector<string> res;
        queue<string> q;
        map<string, bool> visited; //to avoid the cycle
        q.push(target)
        while(!q.empty())
        {
            string lib=q.front();q.pop();
            res.push_back(lib);
            if(dependence.count(lib)==0) continue;
            for(auto l:dependence[lib])
            {
                if(visited.count(l)) continue;
                q.push(l);
            }
            visited[lib]=true;
        }
        return res;
    }
};

