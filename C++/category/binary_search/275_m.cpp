/**
  
275[M]. H-Index 2
 
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
**/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0) return 0;
        int n=citations.size();
        int left=0, right=n-1;
        while(left<=right)
        {
            int mid=left+(right-mid)/2;
            if(citations[mid]==n-mid) return n-mid;
            else if(citations[mid]>n-mid)right=mid-1;
            else left=mid+1;
        }
        return n-left;
    }
};

