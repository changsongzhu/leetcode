
class Solution{
public:
    vector<vector<string> > menu(vector<vector<string>  > &menu, vector<vector<string>  > &person)
    {
        map<string, vector<string>  > m; // Dish type
        for(int i=0;i<menu.size();i++)
        {
            m[menu[i][1]].push_back(menu[i][0]);
        }
        vector<vector<string> > res;
        for(int i=0;i<person.size();i++)
        {
            string name=person[i][0];
            if(person[i][1]=="*")
            {
                for(auto a:m)
                {
                    for(auto b:a.second)
                        res.push_back({name, b});
                }
            }
           else
           {
                for(auto a:m[person[i][1]])
                {
                    res.push_back({name, a});
                }
           }
        }
        return res;
    }
};

