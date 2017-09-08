#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <time.h>

using namespace std;


int main()
{

   int cnt=0;
   cout<<"[";
   for(int i=19999;i>=0;i--)
   {
       if(cnt!=0&&cnt%20==0) cout<<endl;
       cout<<i<<",";
   }
   cout<<"]";


}
