/**
313[M]. Super Ugly Number
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
**/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes){
       priority_queue<long, vector<long>, greater<long> > pq;
       pq.push(1);
       int start =0;
       int cnt=0;
       while(cnt<n){
           long tmp=pq.top();pq.pop();
           if(tmp>start)
           {
               for(auto p:primes)
                   pq.push(tmp*p);
               start=tmp;
               cnt++;
           }
       }
       return start;
    }
};

 
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
       vector<int> res(1,1);
       vector<int> idx(primes.size(), 0);
       while(res.size()<n)
       {
           vector<int> tmp;
           for(int i=0;i<primes.size();i++)
           {
               tmp.push_back(primes[i]*res[idx[i]]);
           }
           int min_val=INT_MAX;
           for(int i=0;i<tmp.size();i++)
           {
               min_val=min(min_val, tmp[i]);
           }
           for(int i=0;i<primes.size();i++)
           {
               if(min_val==primes[i]*res[idx[i]]) idx[i]++;
           }
           res.push_back(min_val);
       }
       return res.back();
    }
};

