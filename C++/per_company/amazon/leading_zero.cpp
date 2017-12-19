#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <typeinfo>

using namespace std;


class Solution{
public:
    int leadingZero(int num)
    {
        int left=0,right=32;
        while(left<right)
        {
            cout<<"left"<<left<<" "<<"right"<<right<<endl;
            int mid=left+(right-left)/2;
            if(num>>mid)
            {
                 left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return 32-right;
    }
};

int main(void)
{
    Solution solution;
    if(solution.leadingZero(0)!=32) cout<<"Case 0: failed!";
    for(int i=0;i<32;i++)
    {
        cout<<"Case......"<<i<<endl;
        int res=solution.leadingZero(1<<i);
        if(res!=31-i)
        {
            cout<<"Case: "<<i<<" Failed "<<endl;
        }
    }
    return 0;
}
