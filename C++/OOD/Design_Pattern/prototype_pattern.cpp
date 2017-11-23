class Shape{
public:
    virtual void draw()=0;
    virtual Shape* clone()=0;
};
class Circle:public Shape{
public:
    void draw(){cout<<"Draw Circle"<<endl;}
    Shape* clone(){return new Circle;}
};
class Rectangle:public Shape{
public:
    void draw(){cout<<"Draw Rectangle"<<endl;}
    Shape* clone(){return new Rectangle;}
};
class Square:public Shape{
public:
    void draw(){cout<<"Draw Square"<<endl;}
    Shape* clone(){return new Square;}
};

class ShapeCache{
private:
    unordered_map<string, Shape*> protoType;
public:
    ShapeCache(){
        protoType["1"]=new Circle;
        protoType["2"]=new Rectangle;
        protoType["3"]=new Square;
    }
    Shape* createShape(string Id){
        if(protoType.count(Id)==0) return NULL;
        else return protoType[Id]->clone();
    }
};
