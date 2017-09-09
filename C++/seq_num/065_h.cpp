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


//Unrefined version

class Solution {
public:
    bool isNumber(string s) {
        if(s.size()==0) return 0;
        int left=0,right=s.size()-1;
        while(left<=right&&s[left]==' ') left++;
        while(left<=right&&s[right]==' ')right--;
        s=s.substr(left, right-left+1);
        if(s.find_first_of(' ')!=string::npos) return false;
        int pos=s.find('e');
        if(pos!=string::npos)
        {
            string s1=s.substr(0, pos);
            if(s1[0]=='+'||s1[0]=='-')s1=s1.substr(1);
            if(s1[0]=='.')
            {
                s1=s1.substr(1);
                if(s1[0]=='.') return false;
            }
            if(s1.back()=='.')
            {
                s1.resize(s1.size()-1);
                if(s1.back()=='.') return false;
            }
            string s2=s.substr(pos+1);
            if(s2[0]=='+'||s2[0]=='-')s2=s2.substr(1);
            if((validNumber(s1)||validDecimal(s1))&&validNumber(s2)) return true;
            else return false;
        }
        
        if(s.find('.')!=string::npos) return validDecimal(s);
        
        if(s[0]=='+'||s[0]=='-') s=s.substr(1);
        return validNumber(s);
        
    }
    
    bool validDecimal(string s)
    {
        int pos=s.find('.');
        if(pos!=string::npos)
        {
            string s1=s.substr(0,pos);
            string s2=s.substr(pos+1);
            if(s1[0]=='+'||s1[0]=='-')s1=s1.substr(1);
            if(s1.size()==0&&s2.size()==0) return false;
            if((s1.size()==0||validNumber(s1))&&(s2.size()==0||validNumber(s2))) return true;
            else return false;
        }
        else
        {
            return false;
        }
    }
    
    bool validNumber(string s)
    {
        if(s.size()==0) return false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>'9'||s[i]<'0') return false;
        }
        return true;
    }
};





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

