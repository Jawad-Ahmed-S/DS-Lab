#include <iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    Node* child;
    public:
    Node(int val){
        data = val;
        next = nullptr;
        child =nullptr;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* n){
        next = n;
    }
    
    Node* getChild(){
        return child;
    }
    void setChild(Node* n){
        child = n;
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
    Node *getHead(){
        return head;
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
    void connectChild(Node *ChildHead,int val){
        Node *curr=head;
        while(curr!=nullptr){
            if(curr->getData()==val){
                curr->setChild(ChildHead);
                return;
            }
            curr=curr->getNext();
        }
    }
};
void display(Node *head){
        
        Node *temp=head;
        while(temp != nullptr){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
    }
Node * flattenList(Node *head){
    if(head==nullptr)return head;


    Node *curr=head;
    while(curr!=nullptr){
        if(curr->getChild()!=nullptr){
            Node *afterChild = curr->getNext();
            curr->setNext(flattenList(curr->getChild()));
            curr->setChild(nullptr);

            while(curr->getNext()!=nullptr){
                curr=curr->getNext();
            }
            if(afterChild!=nullptr){
                curr->setNext(afterChild);
            }

        }
        
        curr=curr->getNext();
    }
    return head;
}
int main() {
    Linkedlist list,childList,grandchildList;
    
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.InsertAtEnd(4);
    list.InsertAtEnd(5);
    childList.InsertAtEnd(22);
    childList.InsertAtEnd(42);
    childList.InsertAtEnd(52);
    childList.InsertAtEnd(72);
    grandchildList.InsertAtEnd(100);
    grandchildList.InsertAtEnd(105);
    grandchildList.InsertAtEnd(400);
    grandchildList.InsertAtEnd(650);
    list.connectChild(childList.getHead(),3);
    childList.connectChild(grandchildList.getHead(),52);

    flattenList(list.getHead());
    list.display();
    return 0;
}