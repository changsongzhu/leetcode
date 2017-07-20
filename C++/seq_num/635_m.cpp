/**
635[M]. Design Log Storage
You are given several logs that each log contains a unique id and timestamp. Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.
Design a log storage system to implement the following functions:
void Put(int id, string timestamp): Given a log's unique id and timestamp, store the log in your storage system.


int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from start to end. Start and end all have the same format as timestamp. However, granularity means the time level for consideration. For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day", it means that we need to find the logs within the range from Jan. 1st 2017 to Jan. 2nd 2017.
Example 1:
put(1, "2017:01:01:23:59:59");
put(2, "2017:01:01:22:59:59");
put(3, "2016:01:01:00:00:00");
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.
Note:
There will be at most 300 operations of Put or Retrieve.
Year ranges from [2000,2017]. Hour ranges from [00,23].
Output for Retrieve has no order required.
**/

class LogSystem {
public:
    LogSystem() {
    }
    vector<int> stringToV(string time)
    {
        vector<int> res(6,0);
        for(int i=0;i<6;i++){
           if(i!=5){
               int pos=t.find_first_of(":");
               res[i]=stoi(to_string(0, pos));
               t=t.substr(pos+1);
           }else{
               res[i]=stoi(t);
           }
        }
        return res;
    }
    long long convert(vector<int> st)
    {
        st[1] = st[1] - (st[1] == 0 ? 0 : 1);
        st[2] = st[2] - (st[2] == 0 ? 0 : 1);
        return (st[0] - 1999L) * (31 * 12) * 24 * 60 * 60 + st[1] * 31 * 24 * 60 * 60 + st[2] * 24 * 60 * 60 + st[3] * 60 * 60 + st[4] * 60 + st[5];
    }
    void put(int id, string timestamp) {
        logs.push_back({convert(stringToV(timestamp)), id});
    }
    vector<int> retrieve(string s, string e, string gra) {
        long long start=granularity(s, gra, false);
        long long end=granularity(e, gra, false);
        vector<int> res;
        for(auto log:logs){
            if(log.first>=start&&log.first<end) res.push_back(log.second);
        }
        returnr res;
    }
    long long granularity(string s, string gra, bool end)
    {
        map<string, int> m;
        m["Year"]=0;m["Month"]=1;m["Day"]=2;m["Hour"]=3;m["Minute"]=4;m["Second"]=5;
        vector<int> res = stringToV(s);
        for(int i=m[gra]+1;i<6;i++)
            res[i]=0;
        if(end) res[m[gra]]++;
        return convert(res);
    }
private:
    vector<pair<long long, int> > logs;
};

