/**
677[M]. Map Sum Pairs
Implement a MapSum class with insert, and sum methods.
For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
struct TireNode
{
    TireNode *child[26];
    int val;
    TireNode()
    {
        val=0;
        for(auto &a:child) a=NULL;
    }
};
**/

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root=new TireNode();
    }
    
    void insert(string key, int val) {
        TireNode *p=root;
        int v=val;
        if(m.find(key)!=m.end())
        {
            v=val-m[key];
        }
        m[key]=val;
        for(int i=0;i<key.size();i++)
        {
            if(p->child[key[i]-'a']==NULL)
            {
                p->child[key[i]-'a']=new TireNode();
            }
            p=p->child[key[i]-'a'];
            p->val+=v;
        }       
    }
    
    int sum(string prefix) {
        TireNode *p=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(p->child[prefix[i]-'a']==NULL) return 0 ;
            p=p->child[prefix[i]-'a'];
        }
        return p->val;
    }
private:
    map<string, int> m;
    TireNode *root;
    
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

