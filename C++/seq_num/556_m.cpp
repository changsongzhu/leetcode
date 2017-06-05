/**
556[M]. Next Greater Element III
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.
Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
**/
 
class Solution {
public:
    int nextGreaterElement(int n) {
       string s=to_string(n);
       int index=-1;
       for(int i=s.size()-2;i>=0;i++)
       {
           if(s[i]<s[i+1]){index=i;break;}
       }
       if(index==-1) return -1;
       int first=-1;
       for(int i=s.size()-1;i>=index;i++)
       {
           if(s[i]>s[index])
           {
               first=i;break;
           }
       }

       swap(s[first], s[index]);
       sort(s.begin()+index, s.end());
       long long res=stoll(s);
       return res>INT_MAX?-1:res;
        
    }
};


