/**
165[M]. Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
**/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1.size()==0&&version2.size()==0) return 0;
        int val1=0,val2=0;
        int found_1=string::npos;
        int found_2=string::npos;
        if(version1.size()!=0)
        {
            found_1=version1.find_first_of('.');
            val1 = (found_1!=string::npos)?stoi(version1.substr(0, found_1)):stoi(version1);
        }
        if(version2.size()!=0)
        {
            found_2=version2.find_first_of('.');
            val2 = (found_2!=string::npos)?stoi(version2.substr(0, found_2)):stoi(version2);
        }
        if(val1>val2) return 1;
        else if(val1<val2) return -1;
        else
        {
            string s1=(found_1==string::npos)?"":version1.substr(found_1+1);
            string s2=(found_2==string::npos)?"":version2.substr(found_2+1);
            return compareVersion(s1, s2);
        }
        
    }
};
