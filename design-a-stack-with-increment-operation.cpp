class CustomStack {
    vector<int>stack;
    int top;
    int cap;
public:
    CustomStack(int maxSize) {
        stack = vector<int>(maxSize,0);
        top = -1;
        cap = maxSize;
    }
    
    void push(int x) {
        if(top+1 == cap)return;
        top++;
        stack[top] = x;
    }
    
    int pop() {
        if(top==-1)return -1;

        return stack[top--];
    }
    
    void increment(int k, int val) {
        int c = 0;
        while(c+1<=k && c<cap){
            stack[c++] += val; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */