/*
Parking Lot Design
*/

enum ParkingType{
    REGULAR,
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
            freeParkingSpace.push({parkingSpace[i].distance, i});
        }
        this->freeParkingSpace=parkingSpace.size();
        this->totalParkingSpace=parkingSpace.size();
    }

    bool parkVehicle( Vehicle &vehicle){
        vector<pair<int, int> > tmp;
        while(!freeParkingSpace.empty()){
            auto a=freeParkingSpace.top();freeParkingSpace.pop();
            if(a.parkingType==vehicle.parkingType){
                parkingSpace[a.second].vehicle=vehicle;
                parkingSpace[a.second].isVacant=false;
                m[vehicle.plateId]=a.second;
                break;
            }else {
                tmp.push_back(a);
            }
        }
        for(int i=0;i<tmp.size();i++)freeParkingSpace.push(tmp[i]);
        return m.count(vehicle.plateId)!=0;
    }
   

    void releaseVehicle(Vehicle &vehicle)
    {
        if(m.count(vehicle.plateId)==0) return;
        int idx=m[vehicle.plateId];
        parkingSpace[idx].isVacant=false;
        m.erase(vehicle.plateId);
        freeParkingSpace.push({parkingSpace[idx].distance, idx});
    }   

    int getTotalParkingSpace()
    {
         return parkingSpace.size();
    }

    int isFull()
    {
         return !freeParkingSpace.empty();
    }
    

private:
    vector<ParkingSpace> parkingSpace;
    priority_queue<pair<int, int>, vector<pair<int, int> >, comp> freeParkingSpace;
    unordered_map<string, int> m;
};

