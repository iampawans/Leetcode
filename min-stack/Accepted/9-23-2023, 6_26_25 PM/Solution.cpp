// https://leetcode.com/problems/min-stack

class MinStack {
    int v[10000];
    stack<int> s;
    int head = -1;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        ++head;
        cout<< "Push- val : " << val << " head : " << head << endl;
        v[head] =val;
        
        if(s.empty() || s.top() >= val){ // to maintain min val
            s.push(val);
        }
    }
    
    void pop() {
            cout<< "pop- s.top() : " << s.top() << " v[head] : " << v[head] << endl;
        if(v[head] == s.top()){
            s.pop();
        }
        if(head>=0){
            head--;
        }
        cout << " head : " << head << endl;
    }
    
    int top() {
        if(head >= 0){
            cout << "top - v[head] : " << v[head] << " head : " << head << endl;
            return v[head];
        }
        return 0;
    }
    
    int getMin() {
        if(!s.empty()){
            cout << "getmin - s.top() : " << s.top() << endl;
            return s.top();
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */