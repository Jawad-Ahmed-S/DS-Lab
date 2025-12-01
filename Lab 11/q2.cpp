#include <iostream>
using namespace std;

class Node{
    string data;
    Node *next;
    public:
    Node(string val){
        data = val;
        next = NULL;
    }
    string getVal(){
        return data;
    }
    Node *getNext(){
        return next;
    }
    void setNext(Node *n){
        next = n;
    }
    ~Node(){
        
    }
};
class Linkedlist{
    
    Node *head;
    public:
    Linkedlist(){
        head = nullptr;
    }
    void InsertAtBegining(string data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            newNode->setNext(nullptr);
        }
        else{
            newNode->setNext(head);
            head = newNode;
        }

    }
    Node* getHead(){
        return head;
    }
    void display(){
        Node* curr=head;
        while(curr!=nullptr){
            cout<<curr->getVal()<<" , ";
            curr = curr->getNext();
        }
        cout<<endl;
    }
    
};

class HashMap{
    Linkedlist *array;
    int size;

    public:
    HashMap(){
        size=100;
        array = new Linkedlist[size];
    }
    int hash(string key){
        int sum=0;
        for( char c:key){
            sum+=c;
        }
        return sum%size;
    }
    void Add_Record(string key){
        array[hash(key)].InsertAtBegining(key);
    }
    int search(string key){
        Node *temp = array[hash(key)].getHead();
        while(temp!=nullptr){

            if(key==temp->getVal()){
                return hash(key);
            }
            temp=temp->getNext();
        }
        cout<<"Not Found!"<<endl;
        return -1;
    }
    void display(){
        for(int i=0;i<size;i++){
            if(array[i].getHead()!=nullptr)
            array[i].display();
            cout<<endl;
        }
    }

};
int main() {
    HashMap test;
    test.Add_Record("jawad");
    test.Add_Record("ahmed");
    test.search("jawad");
    test.display();

    return 0;
}