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
    Node *getHead(){
        return head;
    }
    void setHead(Node *ptr){
        head=ptr;
    }
    void display(){
        
        Node *temp=head;
        cout<<endl;
        while(temp != nullptr){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
    }
};

Node* mergeLists(Linkedlist *list1,Linkedlist *list2){
    Node *temp1,*temp2,*curr=nullptr,*head=nullptr;
    temp1 = list1->getHead();
    temp2 = list2->getHead();

    
    if(temp1->getData()<temp2->getData()){
    head=temp1;
    curr=temp1;
    temp1=temp1->getNext();
}
else{
    head=temp2;
    curr=temp2;
    temp2=temp2->getNext();
}

while(temp1!=nullptr && temp2!=nullptr){
    
    if(temp1->getData()<temp2->getData()){
        curr->setNext(temp1);
        temp1=temp1->getNext();
    }
    else{
        curr->setNext(temp2);
        temp2=temp2->getNext();
    }
    curr=curr->getNext();
}
if(temp1==nullptr){
    curr->setNext(temp2);
}
else{
    curr->setNext(temp1);
}

    return head;
}
int main() {
    Linkedlist list1,list2,final;
    
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
    final.setHead(mergeLists(&list1,&list2));
    cout<<"\nMerged List : ";
    final.display();
    return 0;
}