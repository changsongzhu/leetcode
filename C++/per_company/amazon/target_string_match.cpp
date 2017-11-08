class Solution{
public:
    vector<string> matchTargetString(vector<string> &strs, string target)
    {
        vector<string> res;
        for(auto str: strs)
        {
            if(str[0]==target[0]&&str[str.size()-1]==target[target.size()-1])
                res.push_back(str);
        }
       return res;
    }
};
/*
Time Complexity: O(N)
Space Complexity: O(1)



Optimize for multiple call
*/

class Solution{
public:
    Solution(vector<string> &strs){
        for(auto str:strs)
        {
            string tmp=string(1, str[0])+string(1. str[str.size()-1]);
            m[tmp]++;
        }
    }
    bool match(string target){
        string tmp=string(1, target[0])+string(1, target[target.size()-1]);
        return m.count(tmp)!=0;
    }
private:
    map<string, int> m;
    

};

