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
        return “wood”;
    }
};
class Steel:public Material{
public:
     string getMaterial()
     {
         return “steel”;
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
    string material()
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
         type=”table”;
     }
}

class Chair:public Furniture{
public:
    Table(Material*material):Furniture(material)
     {
         type=”chair”;
     }
}


int main(void)
{
    Material *steel = new Steel();
    Material *wood = new Wood();
    Table *stellTable=new Table(steel);
    Table *woodTable=new Table(wood);
     Chair *steelChair = new Chair(steel);
     Chair *woodChair = new Chair(wood);
}


