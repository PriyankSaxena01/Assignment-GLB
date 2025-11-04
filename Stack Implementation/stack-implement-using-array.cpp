class myStack {
  public:
    int top;
    int capacity;
    vector<int> arr;
    myStack(int n) {
        // Define Data Structures'
        top=-1;
        capacity=n;
        arr.resize(n);
    }

    bool isEmpty() {
        // check if the stack is empty
        return (top==-1);
    }

    bool isFull() {
        // check if the stack is full
        if(top==capacity-1)
        return true;
        else
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull())
        {
            cout<<"Stack Overflow";
        }
        else{
        top++;
        arr[top]=x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty())
        {
            // cout<<"stack underflow";
        }
        else
        {
            top--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty())
        {
            // cout<<"stack Underflow";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};