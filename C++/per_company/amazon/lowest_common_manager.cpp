class Employee{
    int id;
    string name;
    vector<Employee> reporters;
};


class Solution{
public:
   Employee findLCM(Employee ceo, Employee e1, Employee e2){
       stack<Employee> stk1;
       stack<Employee> stk2;
       dfs(ceo, e1, stk1);
       dfs(ceo, e2, stk2);
       if(stk1.empty() || stk2.empty() return NULL;
       int size1=stk1.size();
       int size2=stk2.size();
       int diff=abs(size1, size2);
       if(size1>size2)
       {
           moveUp(stk1, diff);
       }
       else
       {
          moveUp(stk2,diff);
       }
      while(!stk1.empty()&&stk1.top().id!=stk2.top().id)
      {
          stk1.pop();
          stk2.pop();
      }
      if(stk1.size()>0) return  stk1.top().id==ceo.id?NULL:stk1.top();
      else return NULL;   
   }

   void moveUp(stack<Employee> &stk, int diff)
   {
       while(!stk.empty()&&diff>0)
       {
           stk.pop();
           diff--;
       }
   }

   bool dfs(Employee root, Employee cur, stack<Employee> &stk)
   {
       stk.push(root);
       if(root.id==cur.id) return true;
       for(auto e: root.reporters)
       {
           bool res=dfs(e, cur, stk);
           if(res==true) return true;
       }
       stk.pop();
       return false;
   }
};

