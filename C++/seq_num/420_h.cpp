/**
420[H]. Strong Password Checker
A password is considered strong if below conditions are all met:
It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.
Insertion, deletion or replace of any one character are all considered as one change.
**/

class Solution {
public:
    int strongPasswordChecker(string s) {
        int n=s.size(), lower=1,upper=1,digit=1;
        int res=0;
        vector<int> v(n, 0);
        for(int i=0;i<n;)
        {
            if(s[i]>='a'&&s[i]<='z') lower=0;
            if(s[i]>='A'&&s[i]<='Z') upper=0;
            if(s[i]>='0'&&s[i]<='9') digit=0;
            int j=i;
            while(j<n&&s[i]==s[j])i++;
            v[j]=i-j;
        }
        int missing=lower+upper+digit;
        if(n<6)
        {
            res=(6-n)+max(0, missing-6+n);
        }
        else
        {
            int over=max(n-20, 0), replace=0, left=0;
            res+=over;
            for(int k=1;k<3;k++)
            {
                for(int i=0;i<n&&over>0;i++)
                {
                    if(v[i]<3&&v[i]%3!=(k-1) ) continue;
                    v[i]-=min(over, k);
                    over-=k;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(v[i]>=3&&over>0)
                {
                    int need=v[i]-2;
                    v[i]-=over;
                    over-=need;
                }
                if(v[i]>=3) left+=v[i]/3;
            }
            res=+max(missing, left);
        }
        return res;
    }
};

