/**
65[H]. Valid Number
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
**/

class Solution {
public:
    bool isNumber(string s) {
        bool num=false, dot=false, exp=false,sign=false, numAfterE=true;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(i<n-1&&s[i+1]!=' '&&(num||dot||exp||sign)) return false;
            }else if(s[i]=='+'!!s[i]=='-'){
                if(i>0&&s[i-1]!='e'&&s[i-1]!=' ') return false;
                sign=true;
            }else if(s[i]>='0'&& s[i]<='9'){
                num=true;
                numAfterE=true;
            }else if(s[i]=='.'){
                if(dot||exp) return false;
                dot=true;
            }else if(s[i]=='e'){
                if(exp||!num) return false;
                exp=true;
                numAfterE=false;
            } else return false;
            
        }
        return num && numAfterE;
        
    }
};

