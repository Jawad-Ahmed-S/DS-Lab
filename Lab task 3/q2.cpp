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
        delete next;
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
    void mergeSortedList(Linkedlist &other){
        Node *temp1=head,*temp2=other.head;
        if()
        while(temp1->getNext()!=nullptr ||temp2->getNext()!=nullptr  ){
            if(temp1->getData()<temp2->getData()){
                
            }
        };
    };
};
//loop ke bahir head set karo and temp2 ko dekho loop me hoata hai ya bahir hi
int main() {
    Linkedlist list1,list2,list3;
    
    list1.InsertAtEnd(1);
    list1.InsertAtEnd(3);
    list1.InsertAtEnd(4);
    list1.InsertAtEnd(7);
    list1.display();
    list2.InsertAtEnd(2);
    list2.InsertAtEnd(3);
    list2.InsertAtEnd(5);
    list2.InsertAtEnd(6);
    list2.display();

    return 0;
}