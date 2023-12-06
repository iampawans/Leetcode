// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int top;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            top =x;
            s1.push(x);
        }
        else{
            s1.push(x);
        }
    }
    
    int pop() {
        int item = top;
        while(!s1.empty()){
            if(top != s1.top()){
                s2.push(s1.top());
                s1.pop();
            }
            else{
                s1.pop();
            }
        }
        while(!s2.empty()){
            if(!s1.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            else{
                top = s2.top();
                s1.push(s2.top());
                s2.pop();               
            }
        }
        return item;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        if(s1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */