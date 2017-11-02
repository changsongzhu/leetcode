/**
373[M]. Find K Paris with Smallest Sums
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 
Return: [1,2],[1,4],[1,6]
 
The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 
Return: [1,1],[1,1]
 
The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3
 
Return: [1,3],[2,3]
 
All possible pairs are returned from the sequence:
[1,3],[2,3]
**/


//Maxheap Solution
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(), n=nums2.size()
        struct comp{
           bool operator()(pair<int, int> &a, pair<int, int> &b){return a.first+a.second<b.first+b.second;}
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
        for(int i=0;i<min(k,m);i++)
        {
             for(int j=0;j<(k, n);j++)
             {
                 pq.push({nums1[i], nums2[j]});
                 if(pq.size()>k) pq.pop();
             }
        }
        vector<pair<int, int> > res;
        while(!pq.empty()){res.push_back(pq.top());pq.pop();}
        return res;
    }
};

 
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > res;
        for(int i=0;i<min((int)nums1.size(), k);i++)
        {
            for(int j=0;j<min((int)nums2.size(), k);j++)
            {
                res.push_back({nums1[i], nums2[j]});
            }
        }
        sort(res.begin(), res.end(), [](pair<int, int> &a, pair<int, int>&b){return a.first+a.second<b.first+b.second;});
        if(res.size()>k) res.erase(res.begin()+k, res.end());
        return res;
    }
};

