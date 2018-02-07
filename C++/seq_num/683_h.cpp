/**
683[H] K empty Slots
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.
Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.
For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.
Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.
If there isn't such day, output -1.
Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.


Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1


Note:
The given array will be in the range [1, 20000].
**/

/*Slide Window Solution*/
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        if(flowers.size()<k+2) return -1;
        int n=flowers.size();
        vector<int> days(n, 0);
        set<int> s;
        for(int i=0;i<n;i++){
            days[flowers[i]-1]=i+1;
        }
        for(int i=0;i<k+1;i++){
            s.insert(days[i]);
        }
        int res=days.size();
        for(int i=k+1;i<days.size();i++){
            int begin=days[i-k-1];
            int end=days[i];
            s.erase(begin);
            if(k==0||(*s.begin()>begin&&*s.begin()>end)){
                res=min(res, max(begin, end));
            }
            s.insert(end);
        }
        return res==days.size()?-1:res;
    }
};

 
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n=flowers.size();
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(flowers[i]);
            if(s.size()>1)
            {
                auto it=s.find(flowers[i]);
                if(it!=s.begin())
                {
                    if(flowers[i]-*(--it)==k+1) return i+1;
                    it++;
                }
                if(it!=s.end())
                {
                    if(*(++it)-flowers[i]==k+1) return i+1;
                }
            }       
        }
        return -1;
    }
};
 
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n=flowers.size();
        set<int>s;
        for(int i=0;i<n;i++)
        {
            auto it= s.insert(flowers[i]).first;
            if(it!=s.begin())
            {
                if(flowers[i]-*(--it)==k+1) return i+1;
                it++;
            }
            if(it!=s.end())
            {
                if(*(++it)-flowers[i]==k+1) return i+1;
            }        
        }
        return -1;
    }
};

