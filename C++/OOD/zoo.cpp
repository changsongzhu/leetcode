Design a Zoo

class Animals{
public:
    Animals(string name, string type, string id):name(name), type(type), id(id){}
private:
    string name;
    string type;
    string id;
    
};

class Zone{
public:
    Zone(int id, string name):id(id), name(name){}
private:
    int id;
    string name;
    string from;
};

class Asian:public Zone{
    Zone(int id, string name):zoneId(id), zoneName(name){}
private:
    int zoneId;
    string zoneName;
    vector<Animals> animals;
};

class Visitor{
    Visitor(string type, bool memebership){}
private:
    string type;
    bool membership;
}

class Zoo{
public:
    void incVisitor(){}
    void decVistor(){}
    string getOpenTime(){}
    string getCloseTime(){}
    void addAnimal(Animal &a){}
    void removeAnimal(Animal &a){}
    int getPrice(){}
    int getVisitorsNum(){}

private:
    vector<Zone> zones;
    set<Visitor> visitors;
    int vistors;
    string openTime;
    string closeTime;
    string price;
}


