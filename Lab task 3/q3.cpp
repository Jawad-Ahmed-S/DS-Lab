#include <iostream>
using namespace std;
class Node{
    int data;
    Node* next;
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
    
    ~Node(){
        
    }
};
class Linkedlist{
    Node * head;
    public:
    Linkedlist(){
        head=nullptr;
    }
    void InsertAtEnd(int val){
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
    void display(){
        
        Node *temp=head;
        while(temp != nullptr){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
    }
};

int main() {
    Linkedlist list;
    
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.InsertAtEnd(4);
    list.InsertAtEnd(5);
    list.InsertAtEnd(6);
    list.InsertAtEnd(7);
    list.display();
    return 0;
}