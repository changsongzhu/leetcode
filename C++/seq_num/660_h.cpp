/**

660[H]. Remove 9
Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...
So now, you will have a new integer sequence: 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...
Given a positive integer n, you need to return the n-th integer after removing. Note that 1 will be the first integer.
Example 1:
Input: 9
Output: 10


Hint: n will not exceed 9 x 10^8.
**/
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int newInteger(int n) {
       if(n<9) return n;
       int level=1;
       long long level_factor=8;
       long long m=1;
       long long num= (long long)n;
       while(n>level_factor)
       {
           num-=level_factor;
           level_factor*=9;
           level++;
           m*=9;
       }
       int d=0, r=0;
       int res=0;
       for(int i=1;i<level;i++)
       {
           d=num/m;
           r=num%m;
           if(i==1)
           {
               if(r==0)
               {
                   res=res*10+d*10;
                   num=num-(d-1)*m;
               }
               else
               {
                   res=res*10+(d+1)*10;
                   num=num-d*m;
               }
               
           }
           else
           {
              if(r==0)
              {
                  res=res*10+(d-1)*10;
                  num=num-(d-1)*m;
              }
              else
              {
                  res=res*10+d*10;
                  num=num-d*m;
              }
           }
           
           if(i==level-1) 
           {
               res=res+(r==0?8:r-1);
           }
           m=m/9;
       }
       return res;
    }
};


int main(void)
{
    Solution solution;
    //cout<<"newInteger(8)= " << solution.newInteger(8) << endl;
    //cout<<"newInteger(9)= " << solution.newInteger(9) << endl;
    //cout<<"newInteger(80)= " << solution.newInteger(80) << endl;
    //cout<<"newInteger(81)= " << solution.newInteger(81) << endl;
    //cout<<"newInteger(161)= " << solution.newInteger(161) << endl;
    //cout<<"newInteger(162)= " << solution.newInteger(162) << endl;
    cout<<"newInteger(800000000)= " << solution.newInteger(800000000) << endl;

}


