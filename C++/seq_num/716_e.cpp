/**
716[E]. Max Stack
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
**/
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        mx=INT_MIN;
    }
    
    void push(int x) {
        stk.push({x, mx});
        mx=max(mx, x);
    }
    
    int pop() {
        if(!stk.empty())
        {
            auto a=stk.top();stk.pop();
            mx=a.second;
            return a.first;       
        }
    }
    
    int top() {
        return stk.top().first;
    }
    
    int peekMax() {
        return mx;
    }
    
    int popMax() {
        stack<pair<int, int> > tmp;
        int res=mx;
        while(!stk.empty())
        {
            if(stk.top().first==mx)
            {
                mx=stk.top().second;
                stk.pop();
                break;
            }
            else
            {
                tmp.push(stk.top());
                stk.pop();
            }
        }
        while(!tmp.empty())
        {
            stk.push({tmp.top().first, mx});
            mx=max(mx, tmp.top().first);
            tmp.pop();
        }
        return res;
        
    }
private:
    int mx;
    stack<pair<int, int> > stk;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
