#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <time.h>

using namespace std;

int google_num=50;
int google[] = { 
		 4, 10, 17, 20, 22, 23, 31, 42, 50, 54, 56, 66, 128, 133, 139, 140, 146, 155, 162, 166, 173, 200, 208, 214, 218,
		 224, 228, 231, 240, 257, 279, 280, 282, 289, 295, 297, 312, 315, 316, 318, 326, 336, 345, 374, 388, 421, 448, 463, 534, 535,
    
};

int facebook_num=50;
int facebook[] = {
		 1, 10, 13, 15, 17, 20, 23, 26, 28, 33, 38, 43, 49, 50, 56, 67, 69, 76, 78, 79, 85, 88, 91, 102, 121,
		 125, 127, 128, 139, 146, 168, 173, 200, 206, 215, 218, 234, 235, 236, 238, 273, 278, 282, 283, 297, 301, 334, 461, 534, 535,

};

int linkedin_num=45;
int linkedin[] = {
		 1, 21, 23, 33, 34, 46, 47, 50, 53, 56, 57, 65, 68, 76, 101, 102, 103, 104, 127, 149, 150, 152, 156, 170, 173, 187, 198, 205,
    		 236, 238, 243, 244, 245, 254, 256, 277, 297, 311, 339, 364, 366, 367, 464, 515, 605,

};

int amazon_num=100;
int amazon[] = {
		 1, 2, 3, 5, 8, 15, 17, 20, 21, 23, 42, 48, 49, 73, 78, 89, 98, 102, 119, 121, 126, 127, 138, 139, 141, 146, 155, 160, 167,
		 199, 200, 204, 206, 215, 234, 235, 236, 238, 239, 240, 242, 297, 380, 387, 396, 451, 460, 534, 535, 617,

};


int main()
{

   set<int> s;
   map<int, int> f;
   map<int, int> l;
   map<int, int> a;
   map<int, int> g;
   for(int i=0;i<facebook_num;i++) f[facebook[i]]++;
   for(int i=0;i<linkedin_num;i++) l[linkedin[i]]++;
   for(int i=0;i<amazon_num;i++) a[amazon[i]]++;
   for(int i=0;i<google_num;i++) g[google[i]]++;

   vector<int> all;
   for(int i=0;i<facebook_num;i++)
   {
       if(l.count(facebook[i])&&a.count(facebook[i])&&g.count(facebook[i]))
           all.push_back(facebook[i]);
   }
   cout<<"FLAG Common Questions"<<endl;
   for(int i=0;i<all.size();i++)
   {
        cout<<all[i]<<" ";   
   }
   cout<<endl;

   vector<int> f_l_g;
   for(int i=0;i<facebook_num;i++)
   {
       if(l.count(facebook[i])&&g.count(facebook[i]))
           f_l_g.push_back(facebook[i]);
   }
   cout<<"F_L_G Common Questions"<<endl;
   for(int i=0;i<f_l_g.size();i++)
   {
        cout<<f_l_g[i]<<" ";
   }

   cout<<endl;

   vector<int> l_a;
   for(int i=0;i<linkedin_num;i++)
   {
       if(a.count(linkedin[i]))
           l_a.push_back(linkedin[i]);
   }
   cout<<"L_A Common Questions"<<endl;
   for(int i=0;i<l_a.size();i++)
   {
        cout<<l_a[i]<<" ";
   }

   cout<<endl;

   vector<int> f_g;
   for(int i=0;i<facebook_num;i++)
   {
       if(g.count(facebook[i]))
           f_g.push_back(facebook[i]);
   }
   cout<<"F_G Common Questions"<<endl;
   for(int i=0;i<f_g.size();i++)
   {
        cout<<f_g[i]<<" "; 
   }

   cout<<endl;

}
