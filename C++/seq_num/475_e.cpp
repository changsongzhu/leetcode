/**
475[E] Heaters
 
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
**/


//Two Scan Solution
class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters){
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int hNum=heaters.size();
        vector<int> left(houses.size(), INT_MAX);
        vector<int> right(houses.size(), INT_MAX);

        //check the left heaters for each house
        int h_idx=0;
        int h_start=heaters[h_idx];
        for(int i=0;i<houses.size();i++)
        {
            if(h_start<=houses[i])
            {
                while(h_idx+1<hNum&&heaters[h_idx+1]<=houses[i])h_start=heaters[++h_idx];
                left[i]=houses[i]-h_start;
            }

        }
       //check the right heaters for each house
        h_idx=hNum-1;
        h_start=heaters[h_idx];
        for(int i=houses.size()-1;i>=0;i--)
        {
            if(h_start>=houses[i])
            {
                while(h_idx-1>=0&&heaters[h_idx-1]>=houses[i])h_start=heaters[--h_idx];
                right[i]=h_start-houses[i];
            }
        } 
        int res=INT_MIN;
        for(int i=0;i<houses.size();i++)
        {
            res=max(res, min(left[i], right[i]));
        }
        return res;
    }
};


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res=0, n=heaters.size();
        sort(heaters.begin(), heaters.end());
        for(auto house:houses)
        {
            int left=0,right=n;
            int mid=0;
            while(left<right)
            {
                mid=left+(right-left)/2;
                if(heaters[mid]<house)left=mid+1;
                else right=mid;
                
                int dist1=(right==n)?INT_MAX:heaters[right]-house;
                int dist2=(right==0)?INT_MAX:house-heaters[right-1];
                res=max(res,min(dist1,dist2));
            }
        }
        return res;
    }
};
