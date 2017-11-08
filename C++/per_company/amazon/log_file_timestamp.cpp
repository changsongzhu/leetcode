class Solution{
public:
    vector<string> mostAdjacentLine(){

struct comp{
    bool operator()(pair<int, string> p1, pari<int, string>p2) {
        return t1<t2;
    }
};
priority_queue<pair<int, string>, vector<pair<int, string>, comp >  pq;
while(getline(ss, str))
{
    int time=parserTime(str);
    int diff = abs(time-timeStamp);
   pq.push({diff, str});
   if(pq.size()>n) pq.pop();
}
while(!pq.empty())
{
    res.push_back(pq.top().second);
    pq.pop();
}
return res;
}
};

