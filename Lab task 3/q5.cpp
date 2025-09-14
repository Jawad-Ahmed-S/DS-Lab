#include <iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int val){
        data = val;
        next = nullptr;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* n){
        next = n;
    }
    int getData(){
        return data;
    }
    
    ~Node(){}
};
class NodeDLL{
    int data;
    NodeDLL* next;
    NodeDLL* prev;
    public:
    NodeDLL(int val){
        data = val;
        next = nullptr;
    }
    NodeDLL* getNext(){
        return next;
    }
    void setNext(NodeDLL* n){
        next = n;
    }
    void setPrev(NodeDLL*n){
        prev=n;
    }
    NodeDLL *getPrev(){
        return prev;
    }
    int getData(){
        return data;
    }
    
    ~NodeDLL(){}
};
class Linkedlist{
    Node * head;
    public:
    Linkedlist(){
        head=nullptr;
    }
    void InsertAtEndSLL(int val){
        Node * newNode = new Node(val);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node *temp=head;
        while(temp->getNext() != nullptr){
            temp=temp->getNext();
        }
        temp->setNext(newNode);
    }
    
    void displaySLL(){
        
        cout<<"Single Linked List: "<<endl;
        Node *temp=head;
        while(temp != nullptr){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
        cout<<endl;
    }

    void displayDLL(NodeDLL* dllHead){
    cout << "Doubly Linked List: " << endl;
    NodeDLL* temp = dllHead;
    while(temp != nullptr){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}



    void displayCLL(){
        Node* temp = head;
    do {
    cout << temp->getData() << " ";
    temp = temp->getNext();
        } while(temp != head);

        cout<<endl;
        
    }
    void convertToCircular(){
        Node * temp =head;
        cout<<"Temp = head"<<endl;
        while(temp->getNext()!=nullptr){
            temp=temp->getNext();
        }   
        cout<<"Converting circular"<<endl;
        temp->setNext(head);
        cout<<"Converted to circular"<<endl;
    }
    NodeDLL* convertToDoubly(){
        if(head==nullptr)
        return nullptr;
        cout<<"Temp != head"<<endl;
        
        Node* temp=head;
        cout<<"Temp = head"<<endl;
        NodeDLL* dllHead=new NodeDLL(temp->getData());
        NodeDLL* prev = dllHead;
        temp=temp->getNext();
        
        cout<<"before loop"<<endl;
        while(temp!=nullptr){
            NodeDLL *newNode = new NodeDLL(temp->getData());
            prev->setNext(newNode);
            newNode->setPrev(prev);
            prev=newNode;
            temp=temp->getNext();
        }
        return dllHead;
    }
};
int main() {
    Linkedlist list,list1;
    
    list.InsertAtEndSLL(2);
    list.InsertAtEndSLL(3);
    list.InsertAtEndSLL(1);
    list.InsertAtEndSLL(1);
    list.displaySLL();
    list1.InsertAtEndSLL(2);
    list1.InsertAtEndSLL(3);
    list1.InsertAtEndSLL(1);
    list1.InsertAtEndSLL(1);
    list1.displaySLL();
    
    list.convertToCircular();
    list.displayCLL();
    NodeDLL *headDLL =list1.convertToDoubly();
    list1.displayDLL(headDLL);
    return 0;
}