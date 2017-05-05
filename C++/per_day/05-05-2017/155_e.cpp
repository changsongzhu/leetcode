/**
155[E]. Min Stack
 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.

minStack.pop();
minStack.top();	  --> Returns 0.
minStack.getMin();   --> Returns -2.

**/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val=INT_MAX;    
    }
    
    void push(int x) {
        stk.push(pair<int, int>(x, min_val));
        min_val=min(min_val, x);
    }
    
    void pop() {
        if(!stk.empty())
        {
            min_val=stk.top().second;
            stk.pop();
        }
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return min_val;
    }
private:
    stack<pair<int, int> > stk;
    int min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
