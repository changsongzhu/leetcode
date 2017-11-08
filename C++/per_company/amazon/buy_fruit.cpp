class Solution{
public:
    bool check(<vector<vector<string> > &codeList, vector<string> &cart)
    {
        vector<string> mergedList;
        for(auto a:codeList)
            for(auto b:a)
                mergedList.push_back(b);
        int j=0;
        for(int i=0;i<=cart.size()-mergedList.size();i++)
        {
            while(j<mergedList.size()&&(mergeddList[j]==cart[i+j]||mergedList[j]==”anything”)
                j++;
            if(j==mergedList.size()) return 1;
            j=0;
        }
        return 0;
    }
   };


class Solution{
public:
    bool check(<vector<vector<string> > &codeList, vector<string> &cart)
    {
        vector<string> mergedList;
        for(auto a:codeList)
            for(auto b:a)
                mergedList.push_back(b);

        int j=0;
        int i=0;
        while(j<mergedList.size()&&i<cart.size()){
            if(mergedList[j]==”anything”||mergedList[j]==cart[i]){
                j++;
                i++;
            }
            else{
                i++;
            }
        }
        if(j==mergedList.size()) return 1;
        return 0
    }
};

