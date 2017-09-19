/**
331[M]. Verify Preorder Serialization of a Binary Tree

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
     _9_
    /   \
   3 	2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true
Example 2:
"1,#"
Return false
Example 3:
"9,#,#,1"
Return false
**/

//Refined Solution
class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream in(preorder);
        string val;
        int d=0;
        vector<string> v;
        while(getline(in, val, ',')) v.push_back(val);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]=="#")
            {
                if(d==0) return false;
                d--;
            }
            else
                d++;
        }
        return d!=0?false:v.back()=="#";
    }
};


#include <string>
#include <stack>
#include <iostream>
#include <stdlib.h>


using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
       stack<char> stk;
       preorder.push_back(',');
       int start=0;
       for(int i=0;i<preorder.size();i++){
          if(preorder[i]==','){
             string tmp=preorder.substr(start, i-start);
             if(tmp=="#") stk.push('#');
             else stk.push('*');
             start=i+1;
          }
       }
       
       stack<char> stk2;
       while(stk.size()>1){
          if(stk.top()!='#') return false;
          bool found=false;
          while(!stk.empty()){
              char a=stk.top();stk.pop();
              cout <<"a= "<< a << endl;
              if(a=='#'){
                 if(stk.empty()){stk2.push(a);break;}
                 char b=stk.top();stk.pop();
                 cout <<"b= "<< b << endl;
                 if(b=='#'){
                    if(stk.empty()){stk2.push(a);stk2.push(b);break;}
                    char c=stk.top();stk.pop();
                    cout <<"c= "<< c << endl;
                    if(c=='*'){
                       cout << "found" << endl;
                       found=true;
                       stk2.push('#');
                    }else {
                       stk2.push(a);stk.push(c);stk.push(b);
                    }
                 } else{
                    stk2.push(a);stk2.push(b);
                 }
              } else {
                    stk2.push(a);
              }
          }
          while(!stk2.empty()){
              stk.push(stk2.top()); stk2.pop();
          }
          if(found==false) break;
       }
       cout<<"Stack Size " <<stk.size()<<endl;
       if(stk.size()==1&&stk.top()=='#') return true;
       else return false;
    }
};


int main(void)
{
   Solution solution;
   string path="1,#,#,#,#";
   bool result=solution.isValidSerialization(path);
   cout << "Is valid Binary Tree: " << result << endl;
   return 0;
}
