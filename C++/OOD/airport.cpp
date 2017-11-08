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
        arrival_queue.push(airplane);
    }

    void processing()
    {
         while(1)
         {
             int time=time();
             if(!arrival_queue.empty()&&time==arrival_queue.top().arrivalTime)
             {
                   Runway &runway=reserveRunway();
                   Airplane airplane=arrival_queue.top();
                   arrival_queue.pop();
                   airplane.landing(runway);
                   depart.push(airplane);
                   releaseRunway();
             }
             int time=time();
              if(!depart_queue.empty()&&time==depart_queue.top().arrivalTime)
              {
                  Runway &runway=reserveRunway();
                  Airplane airplane=depart_queue.top();
                  depart_queue.pop();
                  airplane.takeoff(runway);
                  releaseRunway();
              }   
         }
    }

    struct depComp{
        bool operator()(Airplane& A, Airplane & B){
            return A.departTime>B.departTime;
        }
    };
   struct arrComp{
        bool operator()(Airplane& A, Airplane & B){
            return A.arrivalTime>B.arrivalTime;
        }
    };
private:
    vector<Runway> runway;
    priority_queue<Airplane, vector<Airplane>, depComp>depart_queue;
    priority_queue<Airplane, vector<Airplane>, arrComp>arrival_queue;
};

