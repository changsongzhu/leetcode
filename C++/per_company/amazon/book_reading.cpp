class Solution{
public:
    bool exist(Page page)
    {
        return pos.count(page)!=0;
    }
    vector<Page> nextFewPages(Page page, int num)
    {
        if(pos.count(page)==0) return {};
        list<Page>::iterator it=pos[page];
        vector<Page> res;
        for(int i=0;i<num&&it!=list.end();i++)
        {
            res.push_back(*it);
            it++;
        }
        return res;
    }
    void remove(Page page){
        if(pos.count(page)==0) return;
        list.erase(pos[page]);
    }


private:
    list<Page> pages;
    map<Page, list<Page>::iterator> pos;
};

