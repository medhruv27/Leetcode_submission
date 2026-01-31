class node{
    public: 
    int data;
    int mini;
    node *next;
    node(int data,int mini){
        this->data = data;
        this->mini = mini;
        this->next = NULL;
    }
};

class MinStack {
public:
    node *head = NULL;
    MinStack() {}
    void push(int val) {
        if(head == NULL){
            node *newNode = new node(val,val);
            head = newNode;
        }
        else{
            int mini = min(val,head->mini);
            node *newNode = new node(val,mini);
            newNode->next = head;
            head = newNode;
        }
    }
    
    void pop() {
        head = head -> next;
    }
    int top() {
        return head -> data;
    }
    int getMin() {
        return head -> mini;
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