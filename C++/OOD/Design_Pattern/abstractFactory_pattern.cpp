class Shape{
public:
    virtual void draw()=0;
};
class Color{
public:
    virtual void paint()=0;
};

class Circle:public Shape{
public:
    void draw(){
        cout<<"Draw circle"<<endl;
    }
};

class Red:public Color{
public:
    void paint(){
        cout<<"Paint Red"<<endl;
    }
};

class AbstractFactory{
public:
    virtual Shape* getShape(string shapeType)=0;
    virtual Color* getColor(string colorType)=0;
}

class ShapeFactory:public AbstractFactory{
public:
    Shape* getShape(string shapeType){
        if(shapeType=="Circle"){
            return new Circle;
        }else {
            return NULL;
        }
    }
    Color *getColor(){return NULL;}
};
class colorFactory:public AbstractFactory{
public:
    Shape *getShape(string *shapeType){return NULL;}
    Color *getColor(string *colorType){
        if(colorType=="Red"){
            return new Red;
        }else{
            return NULL;
        }
    }
};

class FactoryProducer{
public:
    AbstractFactory *getFactory(string factoryType){
        if(factoryType=="Color"){
            return new colorFactory;
        }else if(factoryType=="Shape"){
            return new ShapeFactory;
        }
    }
};
