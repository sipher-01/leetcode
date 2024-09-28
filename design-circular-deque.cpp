class MyCircularDeque {
    vector<int>deque;
    int front, rear, capacity;
public:
    MyCircularDeque(int k) {
        deque.resize(k);
        front = -1;
        rear = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        if(front == -1){front = 0;rear=0;}
        else if(front==0) front = (front -1 + capacity)%capacity;
        else front--;
        deque[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        if(front==-1){front=0;rear=0;}
        else if(rear == capacity-1)rear = (rear+1)%capacity;
        else rear++;
        deque[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        if(front == rear)front=rear=-1;
        else{
            if(front==capacity-1)front=0;
            else front++;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        if(front==rear)front=rear=-1;
        else{
            if(rear==0)rear = capacity-1;
            else rear--;
        }
        return true;
    }
    
    int getFront() {
        return (isEmpty())?-1:deque[front];
        
    }
    
    int getRear() {
        return (isEmpty())?-1:deque[rear];

    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        if((front==0 && rear==capacity-1)|| rear+1==front){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */