ign Airport

class Runway{
public
   Runway()
   {
       vacant=true;
   }
   bool vacant;
};


class Airplane{
    void Airplane(){}
    void landing(Runway &runway){}
    void takeoff(Runway &runway){}
public:
    int id;
    int flight_num;
    int airline;
    int departTime;
    int arrivalTime;
};


class Airport{
public:
    Airport(int runwayNum)
    {
         for(int i=0;i<runwayNum;i++
             runway.push_back(Runway());
    }
    Runway & reserveRunway()
    {
        for(int i=0;i<runway.size();i++)
        {
            if(runway[i].vacant)
            {
                 runway[i].vacant=false;
                 return runway[i];
            }
        }
    }
    void releaseRunway(Runway &runway)
    {
         runway.vacant=true;
    }

    void requestLanding(Airplane& airplane)
    {
        arrival_queue.push(pair<airplane.arrivalTime,airplane>);
    }

    void processing()
    {
         while(1)
         {
             int time=time();
             if(!arrival_queue.empty()&&time==arrival_queue.top().first)
             {
                   Runway &runway=reserveRunway();
                   Airplane airplane=arrival_queue.top().second;
                   arrival_queue.pop();
                   airplane.landing(runway);
                   depart.push(pair<airplane.departTime, airplane>);
                   releaseRunway();
             }
             int time=time();
              if(!depart_queue.empty()&&time==depart_queue.top().first)
              {
                  Runway &runway=reserveRunway();
                  Airplane airplane=depart_queue.top().second;
                  depart_queue.pop();
                  airplane.takeoff(runway);
                  releaseRunway();
              }   
         }
    }

    struct comp{
        bool operator()(pair<int, Airplane> &A, pair<int, Airplane> &B){
            return A.first>B.first;
        }
    };
private:
    vector<Runway> runway;
    priority_queue<pair<int, AirPlane>, vector<pair<int, AirPlane> >, comp>depart_queue;
    priority_queue<pair<int, AirPlane>, vector<pair<int, AirPlane> >, comp>arrival_queue;
};

