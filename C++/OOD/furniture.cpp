ign  Furniture

Bridge Design Pattern

class Material{
public:
    virtual string getMaterial()=0;
};

class Wood:public Material{
public:
    string getMaterial()
    {
        return "wood";
    }
};
class Steel:public Material{
public:
     string getMaterial()
     {
         return "steel";
     }
};

class Furniture{
public:
    Furniture(Material* material){
    {
        this->material=material;
    }
    string type()
    {
        return type;
    }
    string getMaterial()
    {
         return material->getMaterial();
    }
private:
    Material *material;
    string type;
};

class Table:public Furniture{
public:
    Table(Material*material):Furniture(material)
     {
         type="table";
     }
};

class Chair:public Furniture{
public:
    Table(Material*material):Furniture(material)
     {
         type="chair";
     }
};

class FurnitureFactory{
public:
    Furniture * createFurniture(string type, Material *material)
    {
        if(type=="table")
            return new Table(material);
        else if(type=="chair")
            return new Chair(material);
    }
};


int main(void)
{
    Material *steel = new Steel();
    Material *wood = new Wood();
    FurnitureFactory factory;
    Table *stellTable=factory.createFurniture("table",steel);
    Table *woodTable=factory.createFurniture("table",wood);
     Chair *steelChair = factory.createFurniture("chair",steel);
     Chair *woodChair = factory.createFurniture("chair",wood);
}


