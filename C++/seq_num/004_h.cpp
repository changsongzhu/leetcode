/**

4[H]. Median of Two Sorted Arrays
 
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example 1:
nums1 = [1, 3] nums2 = [2]  The median is 2.0
Example 2:
nums1 = [1, 2] nums2 = [3, 4]  The median is (2 + 3)/2 = 2.5 
**/

//Refined Version
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        int mid=(m+n)/2;
        int i=0,j=0;
        double a=0,b=0;
        for(int k=1;k<=mid+1;k++)
        {
            int c=i<m?nums1[i]:INT_MAX;
            int d=j<n?nums2[j]:INT_MAX;
            int val=(c<=d?c:d);
            c<=d?i++:j++;
            if(k==mid) a=val;
            if(k==mid+1)b=val;
        }
        if((m+n)&1) return b;
        else return (a+b)/2;   
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int mid=(n+m)/2;
        double a=0, b=0;
        for(int i=0,j=0,k=1;k<=mid+1;k++)
        {
            int val=0;
            if((i<n&&j==m)||(i<n&&j<m&&nums1[i]<=nums2[j]))
                val=nums1[i++];
            //else if((i==n&&j<m)||(i<n&&j<m&&nums1[i]>=nums2[j]))
            else
                val=nums2[j++];
            if(k==mid)a=val;
            else if(k==mid+1)b=val;
        }
        if((m+n)&1) return b;
        else return (a+b)/2;
        
    }
};

