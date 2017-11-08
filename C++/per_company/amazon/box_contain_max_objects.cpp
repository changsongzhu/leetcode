class Solution
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

