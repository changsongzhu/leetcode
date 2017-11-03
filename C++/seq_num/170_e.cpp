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

//Right Solution : unordered_multiset
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto n:nums)
        {
            int count=(n==value-n?2:1);
            if(nums.count(value-n)>=count) return true;
        }
        return false;
    }

private:
    unordered_multiset<int> nums;
};


//TLE Solution
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
