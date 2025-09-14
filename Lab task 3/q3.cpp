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
    Node* getHead(){
        return head;
    }
    void setHead(Node * n){
        head=n;
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
Node *reverseList(Node *head,int k){
    Node *temp = head;
    for(int i=0;i<k;i++){
        if(temp==nullptr){
            return head;
        }
        temp=temp->getNext();
    }
    
    Node* newNext=reverseList(temp,k);

    temp=head;
    Node*next;
    for(int i=0;i<k;i++){
        next=temp->getNext();
        temp->setNext(newNext);
        newNext=temp;
        temp=next;
    }
    head=newNext;
    return head;
}
int main() {
    Linkedlist list;
    
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.InsertAtEnd(4);
    list.InsertAtEnd(5);
    list.InsertAtEnd(6);
    list.InsertAtEnd(7);
    list.InsertAtEnd(8);
    // list.InsertAtEnd(9);
    list.setHead(reverseList(list.getHead(),3));
    list.display();
    return 0;
}