/**208[M]. Implement Trie (Prefix Tree)
 
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
**/

class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode():isWord(false){
        for(auto &a:child) a=NULL;
    }
};

 
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
 
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p=root;
        for(auto w:word)
        {
            int i=w-'a';
            if(!p->child[i])p->child[i]=new TrieNode();
            p=p->child[i]; 
        }
        p->isWord=true;
    }  
    bool search(string word) {
       TrieNode *p=root;
       for(auto w:word)
       {
           int i=w-'a';
           if(!p->child[i]) return false;
           p=p->child[i];
       }
       return p->isWord;
    }
 
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
       TrieNode *p=root;
       for(auto w:prefix)
       {
           int i=w-'a';
           if(!p->child[i]) return false;
           p=p->child[i];
       }
       return true;
    }
private:
    TrieNode *root;
};
 
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
 

