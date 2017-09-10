/**
267[M]. Palindrome Permutation II
 
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
For example:
Given s = "aabb", return ["abba", "baab"].
Given s = "abc", return [].
Hint:
If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
**/

//Right Solution
class Solution {
public:
    vector<string> generatePalindromes(string s) {
		vector<string> palindromes;
        unordered_map<char, int> counts;
        for (char c : s) counts[c]++;
        int odd = 0; char mid; string half;
        for (auto p : counts) {
            if (p.second & 1) {
                odd++, mid = p.first;
				if (odd > 1) return palindromes;
            }
            half += string(p.second / 2, p.first);
        }
        palindromes = permutations(half);
        for (string& p : palindromes) {
            string t(p);
            reverse(t.begin(), t.end());
			if (odd) t = mid + t;
            p += t;
        }
        return palindromes;
    }
private: 
    vector<string> permutations(string& s) {
        vector<string> perms;
        string t(s);
        do {
            perms.push_back(s);
            next_permutation(s.begin(), s.end()); 
        } while (s != t);
        return perms; 
    }
};


//Wrong Solution 
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char, int> mp;
        vector<string> res;
        if(s.size()==0) return res;
        for(auto a:s) mp[a]++;
        string t="", mid="";
        int odd_cnt=0;
        for(auto it:mp)
        {
            if(it.secon%2==1)
            {
                mid+=string(it.second, it.first);
                odd_cnt++;
                if(odd_cnt>1) return res;
            }
            else
                t+=string(it.second/2, it.first);
        }
        helper(res, t, mid, 0);
        return res;
    }
    void helper(vector<string>&res, string t, string mid, int start)
    {
        if(start==t.size())
        {
            res.push_back(t+mid+string(t.rbegin(), t.rend()));
            return;
        }
        for(int i=start;i<t.size();i++)
        {
            if(i!=start&&s[i]==s[start]) continue;
            swap(t[i], t[start]);
            helper(res, t, mid, start+1);
            swap(t[i], t[start]);
        }
    }
};

