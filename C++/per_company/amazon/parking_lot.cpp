class Solution{
public:
    vector<string> parkingLot(string cur, string target)
    {
        map<char, int> m;
        for(int i=0;i<cur.size();i++) m[cur[i]]=i;
        
        int found=target.find(‘_’);
        for(int i=0;i<found;i++)
        {
            if(cur[i]==target[i]) continue;
            if(cur[i]!=’_’)
            {
                int e_idx=m[‘_’];
                swap(cur[e_idx], cur[i]);
                m[‘_’]=i;
                m[cur[i]]=e_idx;
                res.push_back(cur);
            }
            int idx=m[target[i]];
            swap(cur[i], target[i]);
            m[target[i]]=i;
            m[‘_’]=idx;
            res.push_back(cur);
        }
        for(int i=target.size()-1;i>found;i--)
        {
            if(cur[i]==target[i]) continue;
            if(cur[i]!=’_’)
            {
                int e_idx=m[‘_’];
                swap(cur[e_idx], cur[i]);
                m[‘_’]=i;
                m[cur[i]]=e_idx;
                res.push_back(cur);
            }
            int idx=m[target[i]];
            swap(cur[i], target[i]);
            m[target[i]]=i;
            m[‘_’]=idx;
            res.push_back(cur);
        }
        return res;
    }
};

