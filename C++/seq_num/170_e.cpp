/**
170[E]. Two Sum 3 – Data Structure Design
Design and implement a TwoSum class. It should support the following operations:
add and find.
add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

**/

class Solution
{
public:
   void add(int n){
       for(auto a:nums)
       {
           mp[n+a]++;
       }
       nums.push_back(n);
   }

   void find(int n){
       if(mp.find(n) !=mp.end()) return true;
       else return false;
   }
private:
   vector<int> nums;
   map<int, int>mp;
};
