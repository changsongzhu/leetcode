/**
211[M]. Add and Search Word – Date Structure Design
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A .means it can represent any one letter.
For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

**/

class TrieNode{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode():isWord(false){
       for(auto &a:child) a=NULL;
    }
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p=root;
        for(auto w:word){
            int i=w-'a';
            if(!p->child[i]) p->child[i]=new TrieNode();
            p=p->child[i];
        }
        p->isWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
private:
    bool search(string word, int start, TrieNode* root) {
        if(start==word.size()) return root!=NULL&&root->isWord;
        if(start>word.size()||root==NULL) return false;
        if(word[start]=='.'){
            for(int i=0;i<26;i++){
                if(root->child[i]&&search(word, start+1, root->child[i])){
                    return true;
                }
            }
            return false;
        }
        else{
            int i=word[start]-'a';
            if(root->child[i])
                return search(word, start+1, root->child[i]);
            else
                return false;
        }
    }

    TrieNode *root;
};
 
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
 

