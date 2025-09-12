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
    int size=0;
    public:
    Linkedlist(){
        head=nullptr;
        
    }
    void InsertAtEnd(int val){
        Node * newNode = new Node(val);
        if(head==nullptr){
            head=newNode;
            size++;
            return;
        }
        Node *temp=head;
        while(temp->getNext() != nullptr){
            temp=temp->getNext();
        }
        temp->setNext(newNode);
        size++;
    }
    void display(){
        
        Node *temp=head;
        while(temp != nullptr){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
        cout<<endl;
    }
    bool isPalindrome(){
        int *tempArray = new int[size];
        if(head==nullptr){
            return 0;
        }
        Node *temp = head;
        int i=0;
        while(temp!=nullptr){
            tempArray[i]=temp->getData();
            temp=temp->getNext();
            i++;
        }
        int j=size-1;i=0;
        bool flag=1;
        while(i<j){
            if(tempArray[i]!=tempArray[j]){
                flag=0;
            }
        i++;
        j--;
        }
        return flag;

    }
    ~Linkedlist(){
        Node *temp=head;
        if(temp=nullptr){

        }
        while(temp!=nullptr){
            Node *nextnode=temp->getNext();
            delete temp;
            temp=nextnode;
        }
            head=nullptr;


    }
};
int main() {
    Linkedlist list;
    
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.InsertAtEnd(4);
    list.InsertAtEnd(3);
    list.InsertAtEnd(2);
    list.InsertAtEnd(1);
    list.display();
    cout<<"Is it palindrome: "<<(list.isPalindrome()?"Ture":"False");
    return 0;
}