/**
642[H]. Design Search Autocomplete System
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:
The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:
The constructor function:
AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.
Now, the user wants to input a new sentence. The following function will provide the next character the user types:
List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.


Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2]) 
The system have already tracked down the following sentences and their corresponding times: 
"i love you" : 5 times 
"island" : 3 times 
"ironman" : 2 times 
"i love leetcode" : 2 times 
Now, the user begins another search: 

Operation: input('i') 
Output: ["i love you", "island","i love leetcode"] 
Explanation: 
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored. 

Operation: input(' ') 
Output: ["i love you","i love leetcode"] 
Explanation: 
There are only two sentences that have prefix "i ". 

Operation: input('a') 
Output: [] 
Explanation: 
There are no sentences that have prefix "i a". 

Operation: input('#') 
Output: [] 
Explanation: 
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search. 


Note:
The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
Please use double-quote instead of single-quote when you write test cases even for a character input.
Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.
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
