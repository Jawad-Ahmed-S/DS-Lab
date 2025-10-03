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

    class Stack{        
        Node * head;
        int maxSize;
        int currSize =0;
        public:
        Stack(int size){
            head=nullptr;
            maxSize=size;
        }
        void push(int num){
            
            Node * newNode = new Node(num);
            
            if(head==nullptr){
                head = newNode;
            }
            else{
            
                    newNode->setNext(head);
                    head=newNode;
                }

                cout<<"Element Added : "<<num<<endl;
                currSize++;
            
        }
        void pop(){

            Node * temp = head;
            
                if(currSize==0){
                    cout<<"Stack Underflow! "<<endl;
                    return;
                }
                else{

                    head=head->getNext();
                    int val = temp->getData();
                    delete temp;
                    
                    cout<<"Element Removed : "<<val<<endl;
                    currSize--;
                
                }
        }
        int peek(){
            if(head==nullptr){
                cout<<"Stack is empty! "<<endl;
                return 0;
            }
            else{
                return  head->getData();
            }
        }
        bool isEmpty(){
            return (head==nullptr);
                
        }

};
int main() {
    
    Stack s1(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.pop();
    int num = s1.peek();
    cout<<"peek called! \nTop: "<<num<<endl;
    s1.pop();
    s1.pop();
    bool x = s1.isEmpty();
    if(x){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;

    }

    

    return 0;
}