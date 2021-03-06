/**
281[M]. Zigzag Iterator
Given two 1d vectors, implement an iterator to return their elements alternately.
For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
**/
 
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        idx=0;
        int i=0,j=0;
        while(i<v1.size()||j<v2.size())
        {
           if(i<v1.size()&&j<v2.size())
           {
               vec.push_back((i==j)?v1[i++]:v2[j++]);
           }
           else if(i<v1.size())
           {
               vec.push_back(v1[i++]);
           }
           else
           {
               vec.push_back(v2[j++]);
           }
        }
    }
    int next() {
        return vec[idx++];
    }
    bool hasNext() {
        return idx<vec.size();
    }
private:
    vector<int> vec;
    int idx;
};
