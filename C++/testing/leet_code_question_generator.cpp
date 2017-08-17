#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <time.h>

using namespace std;

int size=25;
int pool[] = {
    
/*8-17-2017*/	1, 2, 3, 4, 5, 6, 7, 9, 11, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 27, 28, 30, 32 /* 1-25 */

};


int main()
{

   srand(time(NULL));
   set<int> s;
   for(int i=0;i<10;i++)
   {
       do{
           int val=rand()%size;
           if(s.find(pool[val])==s.end())
           {
               s.insert(pool[val]);
               break;
           }
       }while(1);
   }
   cout<<"Testing Questions is" <<endl;
   for(set<int>:: iterator it=s.begin();it!=s.end();it++)
       cout<<*it<<" ";
   cout<<endl;

}
