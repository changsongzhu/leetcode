/**
264[M]. Ugly Number II
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
**/

class Solution {
public:
    int nthUglyNumber(int n) {
      vector<int> vec;
      vec.push_back(1);
      int n2_idx =0, n3_idx=0,n5_idx=0;
      while(vec.size() < n)
      {
          int nm2 = vec[n2_idx]*2;
          int nm3 = vec[n3_idx]*3;
          int nm5 = vec[n5_idx]*5;
          int min_num = min(nm2,min(nm3,nm5));
          if(min_num == nm2) ++n2_idx;
          if(min_num == nm3) ++n3_idx;
          if(min_num == nm5) ++n5_idx;

          vec.push_back(min_num);
      }
      return vec[n-1];
   }
};
