/**
454[M]. 4Sum II
 
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
 
Output:
2
 
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
**/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res=0;
        int size = A.size();
        if(size==0) return res;
	map<int, int> m1;
        map<int, int> m2;        

        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                m1[A[i]+B[j]]++;
                m2[C[i]+D[j]]++;
            }
        }
        for(auto a:m1)
        {
            if(m2.count(-1*a.first)!=0)
                res+=a.second*m2[-1*a.first];
        }
        return res;
    }
};

