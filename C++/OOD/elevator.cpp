Elevator



class Elevator{
public:
Elevator(int max):maxFloor(max), curFloor(0)
{
}
void moveUp()
{
        curFloor++;        
}
void moveDown()
{
        curFloor--;
}
void doorOpen()
{
}
int getCurFloor(){return curFloor;}
int getDirection(){return direction;};
void run()
{
    while(1)
    {
        if(direction==1)
        {
            while(upReq.size()!=0)
            {
                moveUp();
                if(upReq.count(curFloor)) 
                {
                     doorOpen();
                     upReq.erase(curFloor);
                }
            }
            direction=-1;
        }
        else
        {
             while(downReq.size()!=0)
             {
                 moveDown();
                 if(downReq.count(curFloor))
                 {
                     doorOpen();
                     downReq.erase(curFloor);
                 }
             }
             direction=1;
        }
    }
}
void selectTargetFloor(DIRECTION dir, int targetFloor)
{
    if(dir==UP) upReq.insert(targetFloor);
    if(dir==Down)downReq.insert(targetFloor);
}
private:
    set<int>upReq;
    set<int> downReq;
    int maxFloor;
    int curFloor;
    int direction; // 1: up,  -1: down
};

class RequestProcessor{
public:
    RequestProcessor *getInstance()
    {
        if(instance==NULL)
            instance=new RequestProcessor();
        return instance;
    }

    void initializeElevator(int maxFloor, int elevatorNum)
    {
        this->max_floor=max_floor;
        for(int i=0;i<elevatorNum;i++)
           elevator.push_back(Elevator(maxFloor);
    }

    Elevator selectorElevator(int curFloor)
    {
        int idx=-1;
        int diff=INT_MAX;
       
        for(int i=0;i<elevators.size();i++)
        {
            int tmp=0;  
            int eleCurFloor=elevators[i].getCurFloor();
            int absDist=abs(eleCurFloor-curFloor);
            if(elevators[i].getDirection==UP)
            {
               tmp=eleCurFloor<curFloor?absDist:2*(maxFloor-eleCurFloor)+absDist;
            }
            else if(elevators[i].getDirection==DOWN)
            {
               tmp=eleCurFloor>curFloor?absDist:2*eleCurFloor+absDist;
            }
            if(diff<tmp)
            {
                diff=tmp;
                idx=i;
            }
        }
        return elevators[idx];
    }
    void run()
    {
        pthread_t threads[elevators.size()];
        for(int i=0;i<elevators.size();i++)
        {
            int rc=pthread_create(&threads[i], NULL, &(elevators[i].run), (void*)NULL);
            if(rc) exit(-1);
        }
        pthread_exit(NULL);
    }
private:
    static RequestProcessor *instance;
    RequestProcessor();
    vector<Elevator> elevators;
    int maxFloor;
};

RequestProcessor* RequestProcessor::instance=NULL;

class User{
    void pushButton(int curFloor)
    {
        elevator=RequestProcessor::getInstance()->selectorElevator(curFloor);
    }
    void selectTargetFloor(DIRECTION direction, int targetFloor)
    {
        elevator.selectTargetFloor(direction, targetFloor);
    }
private:
    Elevator elevator;
};

enum DIRECTION{
     UP=1,
     DOWN,
};

