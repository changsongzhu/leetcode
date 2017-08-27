#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <time.h>

using namespace std;

int size=100;
int pool[] = {
    
/*8-17-2017*/1, 2, 3, 4, 5, 6, 7, 9, 11, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 27, 28, 30, 32,                                  /* 001-025 */
/*8-18-2017*/34, 35, 36, 37, 39, 40, 42, 43, 45, 46, 47, 49, 50, 53, 55, 56, 57, 58, 62, 63, 64, 66, 67, 69, 70,                          /* 026-050 */
/*8-21-2017*/73, 74, 75, 76, 77, 78, 79, 80, 82, 83, 86, 87, 88, 89, 90, 92, 93, 94, 95, 96, 98, 99, 100, 101, 102,                       /* 051-075 */
/*8-22-2017*/103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 116, 117, 118, 119, 120, 121, 122, 124, 125, 128, 129, 130, 131, /* 076-100 */
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
               s .insert(pool[val]);
               break;
           }
       }while(1);
   }
   cout<<"Testing Questions is" <<endl;
   for(set<int>:: iterator it=s.begin();it!=s.end();it++)
       cout<<*it<<" ";
   cout<<endl;

}
