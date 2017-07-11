/**
135[H]. Candy
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
**/
class Solution {
public:
    int candy(vector<int>& ratings) {
       int res=0;
       vector<int> nums(ratings.size(), 1);
       for(int i=1;i<ratings.size();i++)
           if(ratings[i]>ratings[i-1]) nums[i]=nums[i-1]+1;
       for(int i=ratings.size()-2;i>=0;i--)
           if(ratings[i]>ratings[i+1]) nums[i]=max(nums[i], nums[i+1]+1);
       for(auto n:nums) res+=n;
       return res;
    }
};

/*Tpcial Wrong Anwser*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        map<int, int> m;
        for(auto r:ratings)m[r]++;
        int res=0;
        int cnt=1;
        for(auto a:m)
        {
           res+=cnt*a.second;
           cnt++;
        }
        return res;
    }
};

