/**
535[M]. Encode and Decode Tiny URL
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
**/

/*Another Solution*/
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(l2s.count(longUrl)!=0) return l2s[longUrl];
        string shortUrl="http://tinyurl.com/000000";
        string dict="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        while(s2l.count(shortUrl)){
            for(int i=1;i<=6;i++){
                shortUrl[shortUrl.size()-i]=dict[rand()%dict.size()];
            }
        }
        s2l[shortUrl]=longUrl;
        l2s[longUrl]=shortUrl;
        return shortUrl;       
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(s2l.count(shortUrl)==0)return "";
        return s2l[shortUrl];
        
    }
private:
    map<string, string> s2l;
    map<string, string> l2s;
};


class Solution {
public:

    Solution()
    {
        s2l.clear();
        l2s.clear();
        dict="1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        srand(time(NULL));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(l2s.count(longUrl))
            return "http://tinyurl.com/"+l2s[longUrl];

        string shortUrl(6,'a');
        for(int i=0;i<6;i++) shortUrl[i]=dict[rand()%62];
        int index=0;
        while(s2l.count(shortUrl))
        {
            shortUrl[index]=dict[rand()%62];
            index=(++index)%5;
        }
        l2s[longUrl]=shortUrl;
        s2l[shortUrl]=longUrl;
        return "http://tinyurl.com/"+shortUrl;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       string s = shortUrl.substr(shortUrl.find_last_of("/")+1);
       return s2l[s];
     
    }
private:
    map<string, string> s2l, l2s;
    string dict;
}; 
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

