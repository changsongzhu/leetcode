Desgin SharedBike

class Bike{
public:
    void lock()
    {
    }
    void unlock()
    {
    }
    void setPos(pair<int, int> position)
    {
        this->pos=position;
    }
    pair<int, int> getPos()
    {
        return pos;
    }
private:
    pair<int, int> pos;
    long long unique_id;
    long long passcode;
    int rate;
};

class RequestProcessCenter
{
public:
    RequestProcessCenter* getInstance()
    {
        if(instance==NULL)
            instance=new RequestProcessCenter();
        return instance;
    }
    vector<Bike>& showNearestBikes(pair<int, int> pos)
    {
        priority_queue<pair<int, int> > pq;
        
        int x=pos.first, y=pos.second;
        for(int i=0;i<bikes.size();i++)
        {
             int dist=(x-bikes[i].pos.first)*(x-bikes[i].pos.first) + 
                         (y-x-bikes[i].pos.second)*(y-x.bikes[i].pos.second);
             pq.push({dist, i});
             if(pq.size()>10) pq.pop();
        }
        vector<Bike> res;
        while(!pq.empty()) {
             res.push_back(pq.top());
             pq.pop();
        }
        return res;
    }
private:
    vector<Bikes> bikes
    static RequestProcessCenter *instance;
};

RequestProcessCenter* RequestProcessCenter::intstance=NULL;

class User{
public:
    User(int x, int y)
    {
        pos.first=x;
        pos.second=y;
    }
    void selectBike()
    {
         vector<Bike> bikes=RequestProcessCenter:getInstance()->findNearestBikes(pos);
         //Choose one by the user
         bike=bikes[rand()%bikes.size()];
    }
    void start()
    {
         Bike.unlock();
         startTime=time();
    }
    void end()
    {
         Bike.lock();
         endTime=time();
    }
    void pay()
    {
         int duration=endTime-startTime;
         int cost=Bike.rate*duration;
    }

private:
    pair<int, int> pos;
    int startTime;
    int endTime;
    Bike bike;
};

