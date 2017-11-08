/**
            User1
      User2       User3
User4   User5
每个User都有自己的朋友，每个User都会推荐一个书单。List<Book>
返回指定一个user关系网中所有人推荐的书。

follow up 如果限制好友关系只能到第二层怎么办？ 查下层数呗。
**/

class Solution{
public:
   vector<Book> commonBooks(map<User, vector<User> > &friends, User &user)
   {
       set<Book> comBook;
       queue<pair<User, int> > q;
       map<User, bool> visited;
       q.push({user, 0});
       while(!q.empty())
        {
             User u=q.top().first;int level=q.top().second;q.pop();
             if(level>2) continue;
             for(auto b:u.Books) s.insert(b);
             for(auto a:m[u])
             {
                  if(visited[a]==true) continue;
                  q.push({a, level+1});
             }
             visited[u]==true;
        }
        return vector<Book>(s.begin(), s.end());
   }
};

