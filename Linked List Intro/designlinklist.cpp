class MyLinkedList {
    private:
    struct Node{
        int data;
        Node* next;
        Node(int n)
        {
            data=n;
            next=NULL;
        }
    };
    Node* head;
    int size;


public:
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1; 
        Node* temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* ptr1=new Node(val);
        ptr1->next=head;
        head=ptr1;
        size++;
    }
    
    void addAtTail(int val) {
        Node* ptr1=new Node(val);
        if(head==NULL)
        head=ptr1;
        else{
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr1;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return; 
        if(index==0)
        {
        Node* ptr1=new Node(val);
        ptr1->next=head;
        head=ptr1;
        size++;
        return;
        }
        int i=0;
        Node* temp=head;
        while(i!=index-1)
        {
        temp=temp->next;
        i++;
        }
        Node* ptr=new Node(val);
        ptr->next=temp->next;
        temp->next=ptr;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) 
        return;
        if(index==0)
        {
            Node*del=head;
            head=head->next;
            delete del;
            size--;
            return;
        }
        int i=0;
        Node* temp=head;
        while(i!=index-1)
        {
            temp=temp->next;
            i++;
        }
        Node* del=temp->next;
        temp->next=del->next;
        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */