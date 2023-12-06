// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int item = q1.back();
        while(!q1.empty()){
            if(item != q1.front()){
                q2.push(q1.front());
                q1.pop();
            }
            else {
                q1.pop();
            }
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return item;
    }
    
    int top() {
        return q1.back();
        
    }
    
    bool empty() {
        if(q1.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */