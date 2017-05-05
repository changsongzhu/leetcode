/**
232[E]. Implement Queue using Stack

Implement the following operations of a queue using stacks.
push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

**/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(stk.empty()) stk.push(x);
        else
        {
            stack<int> tmp_stk;
            while(!stk.empty())
            {
                int tmp=stk.top();
                stk.pop();
                tmp_stk.push(tmp);
            }
            tmp_stk.push(x);
            while(!tmp_stk.empty())
            {
                int tmp=tmp_stk.top();
                tmp_stk.pop();
                stk.push(tmp);
            }
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp= stk.top();
        stk.pop();
        return tmp;
    }
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
private:
    stack<int> stk;
};
