/**
425[H]. Word Square
Given a set of words (without duplicates), find all word squares you can build from them.
A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
b a l l
a r e a
l e a d
l a d y
Note:
1.     There are at least 1 and at most 1000 words.
2.     All words will have the exact same length.
3.     Word length is at least 1 and at most 5.
4.     Each word contains only lowercase English alphabet a-z.
 
Example 1:
Input:
["area","lead","wall","lady","ball"]
 
Output:
[
  [ "wall",
	"area",
	"lead",
	"lady"
  ],
  [ "ball",
	"area",
	"lead",
	"lady"
  ]
]
 
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
 
Example 2:
Input:
["abat","baba","atan","atal"]
 
Output:
[
  [ "baba",
	"abat",
	"baba",
	"atan"
  ],
  [ "baba",
	"abat",
	"baba",
	"atal"
  ]
]
 
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
**/

class Solution {
public:
    struct TrieNode
    {
        TrieNode *child[26];
        vector<int> index;
        TrieNode()
        {
            for(auto &a:child) a=NULL;
        }
    }
    TrieNode * buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for(int i=0;i<words.size();i++)
        {
            TrieNode *r= root;
            for(int j=0;j<word.size();j++)
            {
                if(r->child[words[i][j]-'a']==NULL) r->child[words[i][j]-'a'] = new TrieNode();
                r=r->child[words[i][j]-'a'];
                r->index.push_back(i);
            }
        }
        return root;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root=buildTrie(words);
        vector<vector<string> > res;
        vector<string> out(words[0].size());
        for(word:words)
        {
            out[0]=word;
            dfs(res, out, 1, root, words)
        }
        return res;
    }
    void dfs(vector<vector<string> >&res, vector<string> &out, int level, TrieNode *root, vector<string>&words)
    {
        if(level>=out[0].size())
        {
            res.push_back(out);
            return;
        }
        string str="";
        for(int i=0;i<level;i++)
            str+=out[i][level];

        TrieNode *r=root;
        for(int i=0;i<str.size();i++)
        {
            if(!r->child[str[i]-'a']) return;
            r=r->child[str[i]-'a'];
        }
        for(auto idx:r->index)
        {
            out[level]=words[idx];
            dfs(res, out, level+1, root, words);
        }
    }
    
};

