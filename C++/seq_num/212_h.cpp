/**
212[H]. Word Search II
 
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
For example,
Given words = ["oath","pea","eat","rain"] and board =
[  
['o','a','a','n'],  
['e','t','a','e'],  
['i','h','k','r'],  
['i','f','l','v']
]
Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.
**/
class AutocompleteSystem {
public:
    struct comp{
      bool operator()(pair<string, int>&a, pair<string, int>&b){
          return a.second>b.second||(a.second==b.second&&a.first<b.first);
      }  
    };
    typedef priority_queue<pair<string, int>, vector<pair<string, int> >, comp> my_pq;
    
    struct TrieNode{
        TrieNode *child[27];
        string sentence;
        int times;
        TrieNode():sentence(""), times(0)
        {
            for(auto &c:child) c=NULL;
        }
    };
    struct Trie{
        TrieNode *root;
        Trie()
        {
            root= new TrieNode();
        }
        int toIndex(char c)
        {
            return c==' '?26:c-'a';
        }
        void insert(string sentence, int times)
        {
            TrieNode *p=root;
            for(auto c:sentence)
            {
                if(p->child[toIndex(c)]==NULL) p->child[toIndex(c)]=new TrieNode();
                p=p->child[toIndex(c)];
            }
            p->sentence=sentence;
            p->times=times;
        }
        void add(string sentence)
        {
            TrieNode *p=root;
            for(auto c:sentence)
            {
               if(p->child[toIndex(c)]==NULL) p->child[toIndex(c)]=new TrieNode();
                p=p->child[toIndex(c)]; 
            }
            if(p->times==0)
            {
                p->sentence=sentence;
                p->times++;
            }
            else
            {
                p->times++;
            }
        }
        TrieNode *lookup(string s)
        {
            TrieNode *p=root;
            for(auto c:s)
            {
                if(p->child[toIndex(c)]==NULL) return NULL;
                p=p->child[toIndex(c)];
            }
            return p;
        }
    };
    
    void traversal(TrieNode *p, my_pq &pq)
    {
        if(p==NULL) return;
        if(p->times!=0)
        {
            pq.push({p->sentence, p->times});
            if(pq.size()>3)
            {
                pq.pop();
            }
        }
        for(auto &c:p->child)
        {
            traversal(c, pq);
        }
    }
    
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        this->root= new Trie();
        for(int i=0;i<sentences.size();i++)
        {
            root->insert(sentences[i], times[i]);
        }
        
    }
    

    
    vector<string> input(char c) {
        vector<string> res;
        if(c=='#')
        {
            root->add(inputStr);
            inputStr.clear();
        }
        else
        {
            inputStr.append(1, c);
            TrieNode *p=root->lookup(inputStr);
            if(p==NULL) return res;
            my_pq pq;
            traversal(p, pq);
            for(int i=0;!pq.empty()&&i<3;i++)
            {
                res.insert(res.begin(),pq.top().first);
                pq.pop();
            }
        }
        return res;
        
        
    }
private:
    string inputStr;
    Trie *root;
};
