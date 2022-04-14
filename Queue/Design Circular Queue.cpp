class MyCircularQueue {
public:
    int size;
    int *q;
    int front;
    int rear;
    MyCircularQueue(int k) {
        size = k;
        q = new int[k];
        front = -1;
        rear = -1;
        
    }
    
    bool enQueue(int value) {
        if(front==-1)
        {
            front=0;
            rear++;
            q[rear%size] = value;
            return true;
        }
        
        else{
            
            if((rear+1)%size == front)
                return false;
            
            
            rear = (rear+1)%size; 
            q[rear] = value;
            
            return true;
            
        }
        return false;
    }
    
    bool deQueue() {
        
        if(front==-1)
            return false;
        
        if(front == rear)
        {
            front =-1;
            rear = -1;
            
            return true;
        }
        
        front = (front+1)%size;
        return true;
        
    }
    

    int Front() {
        if(front==-1)
            return -1;
        
        return q[front];
    }
    
    int Rear() {
        
        if(rear==-1)
            return -1;
        
        
        return q[rear];
    }
    
    bool isEmpty() {
        if(front==-1)
            return true;
        
        return false;
    }
    
    bool isFull() {
        int res;
        if(front<=rear)
             res = rear-front+1;
        
        else{
            res = size-front + rear+1;
        }
        
        if(res == size)
            return true;
        
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
