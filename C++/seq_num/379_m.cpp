/**
379[M]. Design Phone Directory
Design a Phone Directory which supports the following operations:
        	get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
 
Example:
 
//Init a phone directory containing a total of 3 numbers: 0,1,and 2.
PhoneDirectory directory = new PhoneDirectory(3); 
 
// It can return any available phone number. Here we assume it returns 0.
directory.get(); 
 
// Assume it returns 1.
directory.get(); 
 
// The number 2 is available, so return true.
directory.check(2); 
 
// It returns 2, the only number that is left.
directory.get(); 
 
// The number 2 is no longer available, so return false. 
directory.check(2); 
 
// Release number 2 back to the pool.
directory.release(2); 
 
// Number 2 is available again, return true.
directory.check(2);
**/
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        occupied.resize(maxNumbers, false);
        for(int i=maxNumbers-1;i>=0;i--)
        {
            stk.push(i);
        }   
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(stk.empty()) return -1;
        int val=stk.top();stk.pop();
        occupied[val]=true;
        return val;
        
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return occupied[number]==false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(occupied[number]==true)
        {
            occupied[number]=false;
            stk.push(number);
        }
    }
private:
    vector<bool> occupied;
    stack<int> stk;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        occupied.resize(maxNumbers, false);
        ListNode *prev=&freeNumber;
        for(int i=0;i<=maxNumbers;i++);
        {
            TreeNode *node=new TreeNode(i);
            prev->next=node;
            prev=node;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(freeNumber.next==NULL) return -1;
        ListNode *tmp=freeNumber.next->next;
        int val=freeNumber.next->val;
        delete freeNumber.next;
        freeNumber.next=tmp;
        occupied[val]=true;
        return val;
        
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !occupied[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        occupied[val]=false;
        TreeNode *node= new TreeNode(number);
        node->next=freeNumber.next;
        freeNumber.next=node;
    }
prvate:
    vector<int> occupied;
    ListNode freeNumber;
};
