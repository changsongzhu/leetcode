#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <time.h>

using namespace std;

int case_num=10;
int size=325;
int pool[] = {
    
/*8-17-2017*/1, 2, 3, 4, 5, 6, 7, 9, 11, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 27, 28, 30, 32,                                  /* 001-025 */
/*8-18-2017*/34, 35, 36, 37, 39, 40, 42, 43, 45, 46, 47, 49, 50, 53, 55, 56, 57, 58, 62, 63, 64, 66, 67, 69, 70,                          /* 026-050 */
/*8-21-2017*/73, 74, 75, 76, 77, 78, 79, 80, 82, 83, 86, 87, 88, 89, 90, 92, 93, 94, 95, 96, 98, 99, 100, 101, 102,                       /* 051-075 */
/*8-22-2017*/103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 116, 117, 118, 119, 120, 121, 122, 124, 125, 128, 129, 130, 131, /* 076-100 */
/*8-23-2017*/133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 147, 148, 150, 151, 155, 157, 158, 159, 160, 161, 162, 164, /* 101-125 */
/*8-24-2017*/167, 168, 179, 171, 173, 179, 186, 187, 189, 190, 198, 199, 200, 201, 202, 203, 204, 205, 206, 209, 213, 215, 216, 217, 219, /* 126-150 */
/*8-25-2017*/222, 225, 226, 229, 230, 231, 232, 234, 235, 237, 238, 239, 242, 243, 245, 246, 247, 250, 251, 252, 253, 255, 256, 257, 258, /* 151-175 */
/*8-26-2017*/260, 263, 264, 266, 268, 270, 271, 276, 278, 280, 281, 282, 283, 285, 286, 287, 288, 289, 290, 292, 293, 294, 295, 297, 298, /* 176-200 */
/*8-27-2017*/303, 304, 306, 311, 314, 318, 319, 328, 329, 333, 338, 339, 341, 342, 344, 345, 346, 347, 348, 349, 350, 353, 359, 360, 362, /* 201-225 */
/*8-28-2017*/366, 367, 369, 370, 371, 372, 373, 374, 380, 382, 383, 384, 387, 389, 392, 396, 397, 398, 400, 401, 405, 406, 408, 409, 412, /* 226-250 */
/*8-29-2017*/414, 415, 416, 419, 421, 422, 423, 434, 435, 437, 438, 439, 442, 445, 447, 448, 449, 451, 452, 453, 454, 455, 459, 461, 462, /* 251-275 */
/*8-29-2017*/463, 472, 485, 494, 496, 500, 503, 504, 506, 507, 508, 513, 515, 520, 521, 522, 523, 524, 525, 526, 530, 531, 532, 533, 535, /* 276-300 */
/*8-29-2017*/536, 537, 538, 539, 541, 543, 545, 548, 549, 551, 553, 554, 556, 557, 560, 561, 563, 566, 567, 572, 575, 581, 582, 592, 593, /* 301-325 */
};

int locked_num=104;
int locked[] = {
             156, 157, 158, 159, 161, 163, 170, 186, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 259, 261, 265,
	     266, 267, 269, 270, 271, 272, 276, 277, 280, 281, 285, 286, 288, 291, 293, 294, 296, 298, 302, 305, 308, 311, 314, 317, 320,
	     323, 325, 333, 339, 340, 346, 348, 351, 353, 356, 358, 359, 360, 361, 362, 363, 364, 365, 366, 369, 370, 379, 408, 411, 418,
	     422, 425, 439, 444, 465, 469, 471, 484, 487, 490, 499, 505, 527, 531, 533, 544, 545, 548, 549, 555, 562, 568, 588, 616, 624, 
             631, 634, 635, 642,

};

int main()
{

   set<int> s;
   map<int, int> m;
   for(int i=0;i<locked_num;i++) m[locked[i]]++;
   srand(time(NULL));
   for(int i=0;i<case_num;i++)
   {
       do{
           int val=rand()%size;
           cout<<"val= "<<val<<endl;
           if(m.find(pool[val])==m.end()&&s.find(pool[val])==s.end())
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