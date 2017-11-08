Parking Lot Design

enum class ParkingType{
    REGULAR =1,
    HANDICAPPED,
    COMPACT,
    MAX_PARKING_TYPE,
};

class Vehicle{
public:
    string plateId;
    ParkingType parkingType;
};

class ParkingSpace{
public:
    bool isVacant;
    Vehicle vehicle;
    ParkingType parkingType;
    int distance;
};

class ParkingLot{
public:
    struct comp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){return a.first>b.first;}
    };
    ParkingLot(vector<ParkingSpace> &parkingSpace)
    {
        this->parkingSpace=parkingSpace;
        for(int i=0;i<parkingSpace.size();i++)
        {
             if(parkingSpace[i].ParkingType==REGULAR)
                 vacantRegularParking.push({parkingSpace[i].distance, i});
            else if(parkingSpace[i].ParkingType==HANDICAPPED)
                 vacantCompactParking.push({parkingSpace[i].distance, i});
            else
                 vacantHandicappedParking.push({parkingSpace[i].distance, i});
        }
    }

    bool parkVehicle( Vehicle &vehicle)
    {
       bool parked=false;
       int parkIdx=-1;
       if(vehicle.ParkingType==HANDICAPPED&&vacantHandicappedParking.size()!=0)
        {
            auto v=vacantHandicappedParking.top();vacantHandicappedParking.pop();
            parkIdx=v.second;
            occupiedHandicappedParking.push_back({parkingSpace[v.second].distance, v.second});
            parked=true;
        }
        if(parked==false&&vacantRegularParking.size()!=0)
        {
auto v=vacantRegularParking.top();vacantRegularParking.pop();
            parkIdx=v.second;
            occupiedRegularParking.push_back({parkingSpace[v.second].distance, v.second});
            parked=true;
        }
        if(parked==false&&vacantCompactParking.size()!=0)
        {
auto v=vacantCompactParking.top();vacantCompactParking.pop();
            parkIdx=v.second;
            occupiedCompactParking.push_back({parkingSpace[v.second].distance, v.second});
            parked=true;
        }
        if(parked)
        {
            parkingSpace[parkIdx].isVacant=false;
            parkingSpace[parkIdx].vehicle=vehicle;
            freeParkingSpace--;
        }
        return parked;
    }
   

 void releaseVehicle(Vehicle &vehicle)
    {
         int i=0;
         for(;i<parkingSpace.size();i++)
         {
              if(parkingSpace[i].vehicle==vehicle)
                  break;
         }
         if(parkingSpace[i].parkingType==HANDICAPPED)
         {
            pair<int, int> last=occupiedHandicappedParking[occupiedHandicappedParking.size()];
            for(int i=0;i<occupiedHandicappedParking.size();i++)
            {
                if(occupiedHandicappedParking[i].second==i)
                {
                    occupiedHandicappedParking[i]=last;
                    occupiedHandicappedParking.pop_back();
                }
            }
            parkingSpace[i].isVacant=true;
            vacantHandicappedParking(parkingSpace[i].distance, i);
         }
         else if(parkingSpace[i].parkingType==REGULAR)
         {
            pair<int, int> last=occupiedRegularParking[occupiedRegularParking.size()];
            for(int i=0;i<occupiedRegularParking.size();i++)
            {
                if(occupiedRegularParking[i].second==i)
                {
                    occupiedRegularParking[i]=last;
                    occupiedRegularParking.pop_back();
                }
            }
            parkingSpace[i].isVacant=true;
            vacantRegularParking(parkingSpace[i].distance, i);
         }
         else if(parkingSpace[i].parkingType==COMPACT)
         {
            pair<int, int> last=occupiedCompactParking[occupiedCompactParking.size()];
            for(int i=0;i<occupiedCompactParking.size();i++)
            {
                if(occupiedCompactParking[i].second==i)
                {
                    occupiedCompactParking[i]=last;
                    occupiedCompactParking.pop_back();
                }
            }
            parkingSpace[i].isVacant=true;
            vacantCompactParking(parkingSpace[i].distance, i);
         }
         freeParkingSpace++;
    }   

    int getTotalParkingSpace()
    {
         return totalParkingSpace;
    }

    int isFull()
    {
         return freeParkingSpace==0;
    }
    

private:
    vector<ParkingSpace> parkingSpace;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> vacantRegularParking;
    vector<pair<int, int> > occupiedRegularParking;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> vacantCompactParking;
    vector<pair<int, int> >  occupiedCompactParking;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> vacantHandicappedParking;
    vector<pair<int, int> >  occupiedHandicappedParking;
    int totalParkingSpace;
    int freeParkingSpace;
};

