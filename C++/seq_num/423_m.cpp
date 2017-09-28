/**
423[M]. Reconstruct Original Digits from English
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"
 
Output: "012"
Example 2:
Input: "fviefuro"
 
Output: "45"
**/

/**

       1st   2nd   3rd
zero:   z

one:          o

two:    w

three:        r

four:   u

five:         f

six:    x

seven:        s

eight:  g            

nine:                i


**/
//Refined Solution
class Solution {
public:
    string originalDigits(string s) {
        vector<int> a(10, 0);
        vector<int> alpha(128, 0);
        for (char c : s)
            alpha[c]++;
        a[0] = alpha['z'];
        a[2] = alpha['w'];
        a[4] = alpha['u'];
        a[6] = alpha['x'];
        a[8] = alpha['g'];
        a[3] = alpha['h'] - a[8];
        a[5] = alpha['f'] - a[4];
        a[7] = alpha['v'] - a[5];
        a[1] = alpha['o'] - a[0] - a[2] - a[4];
        a[9] = alpha['i'] - a[5] - a[6] - a[8];
        string ans;
        for (int i = 0; i < 10; i++) {
            if (a[i] > 0)
                ans += string(a[i], '0' + i);
        }
        return ans;
    }
};

class Solution {
public:
    string originalDigits(string s) {
        vector<int> dict(26, 0);
        vector<int> v(10, 0);
        map<char, int> first={{'z', 0}, {'w', 2}, {'u', 4}, {'x', 6}, {'g', 8}};
        map<char, int> second={{'o', 1}, {'r', 3}, {'f', 5}, {'s', 7}};
        map<char, int> third={{'i', 9}};
        for(auto a:s)dict[a-'a']++;
        for(auto f:first)
        {
            while(dict[f.first-'a'])
            {
                v[f.second]++;
                update(dict, f.second);
            }
        }
        for(auto s:second)
        {
            while(dict[s.first-'a'])
            {
                v[s.second]++;
                update(dict, s.second);
            }
        }
        for(auto t:third)
        {
            while(dict[t.first-'a'])
            {
                v[t.second]++;
                update(dict, t.second);
            }
        }
        string res;
        for(int i=0;i<v.size();i++)
        {
            while(v[i])
            {
               res+=to_string(i);
               v[i]--;
            }
        }
        return res;
  }
    void update(vector<int> &dict, int n)
    {
        switch(n)
        {
            case 0:
                dict['z'-'a']--;dict['e'-'a']--;dict['r'-'a']--;dict['o'-'a']--;
                break;
            case 1:
                dict['o'-'a']--;dict['n'-'a']--;dict['e'-'a']--;
                break;
            case 2:
                dict['t'-'a']--;dict['w'-'a']--;dict['o'-'a']--;
                break;
            case 3:
                dict['t'-'a']--;dict['h'-'a']--;dict['r'-'a']--;dict['e'-'a']--;dict['e'-'a']--;
                break;
            case 4:
                dict['f'-'a']--;dict['o'-'a']--;dict['u'-'a']--;dict['r'-'a']--;
                break;
            case 5:
                dict['f'-'a']--;dict['i'-'a']--;dict['v'-'a']--;dict['e'-'a']--;
                break;
            case 6:
                dict['s'-'a']--;dict['i'-'a']--;dict['x'-'a']--;
                break;
            case 7:
                dict['s'-'a']--;dict['e'-'a']--;dict['v'-'a']--;dict['e'-'a']--;dict['n'-'a']--;
                break;
            case 8:
                dict['e'-'a']--;dict['i'-'a']--;dict['g'-'a']--;dict['h'-'a']--;dict['t'-'a']--;
                break;
            case 9:
                dict['n'-'a']--;dict['i'-'a']--;dict['n'-'a']--;dict['e'-'a']--;
                break;
            default:
                break;
        }
    }
};

