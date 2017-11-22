class Packing{
public:
    virtual string pack()=0;

};

class Item{
public:
    virtual float getPrice()=0;
    virtual string getName()=0;
    string pack(){
        return pack->pack();
    }
private:
    Packing *pack;
};

class Wrapper:public Packing{
public:
   string pack(){ return "Wrapper";}
};

class Bottle:public Packing{
public:
  string pack(){ return "Bottle";}
};

class ColdDrink:public Item{
public:
    pack=new Bottle;
};

class Burger:public Item{
public:
    pack=new Wrapper;
};

class Coke:public ColdDrink{
public:
    float getprice(){return 2.3;}
    string getName(){return "Coke";}
}

class Pepsi:public ColdDrink{
public:
    float getPrice(){return 2.4;};
    string getName(){return "Pepsi";}
};

class VegBurger:public Burger{
public:
    float getPrice(){return 3.5;}
    string getName(){return "VegBurger";}
};

class ChickenBurger:public Burger{
public:
    float getPrice(){return 4.5;}
    string getName(){return "ChickenBurger";
};

class Meal{
public:
   void addItem(Item* item){
       items.push_back(item);
   }
   float totalPrice(){
       float total=0;
       for(auto i:items)
           total+=i->getPrice();
       return total;
   }
   void showItem(){
       for(auto i:items){
           cout<<"Name: "<<i->getName()<<endl;
           cout<<"Price: "<<i->getPrice()<<endl;
           cout<<"Packing: "<<i->pack()<<endl;
        }
   }
private:
    vector<Item*> items;
};

class MealBuilder{
public:
    Meal *prepareVegMeal(){
        Meal vegMeal = new Meal;
        vegMeal->addItem(new VegBurger);
        vegMeal->addItem(new Coke);
        return vegMeal;
    }
    Meal *prepareNonVegMeal(){
        Meal nonVegMeal = new Meal;
        nonVegMeal->addItem(new ChickenBurger);
        nonVegMeal->addItem(new Pepsi);
        return nonVegMeal;
    }
};
