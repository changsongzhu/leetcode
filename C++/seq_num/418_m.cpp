/**
418[M]. Sentence Screen Fitting
Given a rows x cols screen and a sentence represented by a list of words, find how many times the given sentence can be fitted on the screen.
Note:
1.     A word cannot be split into two lines.
2.     The order of words in the sentence must remain unchanged.
3.     Two consecutive words in a line must be separated by a single space.
4.     Total words in the sentence won't exceed 100.
5.     Length of each word won't exceed 10.
6.     1 ≤ rows, cols ≤ 20,000.
 
Example 1:
Input:
rows = 2, cols = 8, sentence = ["hello", "world"]
 
Output:
1
 
Explanation:
hello---
world---
 
The character '-' signifies an empty space on the screen.
 
Example 2:
Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
 
Output:
2
 
Explanation:
a-bcd-
e-a---
bcd-e-
 
The character '-' signifies an empty space on the screen.
 
Example 3:
Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
 
Output:
1
 
Explanation:
I-had
apple
pie-I
had--
 
The character '-' signifies an empty space on the screen.
**/
 
class Solution {
public:
   int wordsTyping(vector<string>& sentence, int rows, int cols) {
       string all="";
       for(auto s:sentence) all+=s+string(" ");
       int start=0,len=all.size();
       for(int i=0;i<rows;i++)
       {
           start+=cols;
           if(all[start%len]==' ')
               start++;
           else 
              while((start>0&&all[(start-1)%len]!=' ')) start--;
       }
       return start/len;
   }
};
