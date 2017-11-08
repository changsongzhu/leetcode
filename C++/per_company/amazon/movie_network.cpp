
class Movie{
public:
    int id;
    int rating;
    vector<Movie> similar;
};

class Solution
{
public:
    vector<int> findKNearest(Movie &movie, int k)
    {
        vector<int> res;
        struct comp{
           bool operator(Movie a, Movie b){
                return a.rating>b.rating;
           }
        };
        priority_queue<Movie, vector<Movie>, comp>  pq;
        queue<Movie> q;
        map<int, int> visited;
        q.push(movie);
        while(!q.empty())
        {
            movie tmp=q.front();q.top();
            for(auto a: tmp.similar)
            {
                if(visited.count(a.id)!=0) continue;
                pq.push(a);
                if(pq.size()>k) pq.pop();
                q.push(a.id);
            }
            visited[tmp.id]++;
        }
        while(!pq.empty())
        {
            res.push_back(pq.top());
           pq.pop();
       }

        return res;
    }
};

