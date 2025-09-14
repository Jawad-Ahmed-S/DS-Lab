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
            newNode->setNext(head);
            return;
        }
        Node *temp=head;
        while(temp->getNext() != head){
            temp=temp->getNext();
        }
        temp->setNext(newNode);
        newNode->setNext(head);
    }
    void display(){
        
        Node *temp=head;
        while(temp != head){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
    }
    void deleteNode(Node* prev){

        Node * n = prev->getNext();
        if(n==head){
            prev->setNext(n->getNext());
            head=n->getNext();
            delete n;
        }else{
            
            prev->setNext(n->getNext());
            
            delete n;
        }
    }
    void JosephusProblem(int k){
        int i=1;
        Node * temp=head;

        while(temp!=temp->getNext()){
            
            if(i==k-1){

                deleteNode(temp);
                
                i=1;
            }
            temp=temp->getNext();
            i++;
        }
        cout<<"\nSurvivor: "<<head->getData();
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
    list.JosephusProblem(3);


    return 0;
}