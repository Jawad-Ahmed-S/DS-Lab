#include<iostream>
using namespace std;
#define Max_Size 5

class Queue{
    int arr[Max_Size];
    int rear=-1;
    int front=-1;
    
    public:
    Queue(){}
    bool isEmpty(){
        if(front==-1 || front>rear){
            return true;
        }
        return false;   
    }
    bool isFull(){
        if(rear==Max_Size-1){
            return true;
        }
        return false;
    }
    void display(){
        for(int i=0;i<Max_Size-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    bool enqeue(int data){
        if(isFull){
            cout<<"Queue full"<<endl;
            return false;
        }
        arr[++rear] = data;
        return true;
    }
    bool dequeue(){
        if(isEmpty){
            cout<<"Queue is Empty"<<endl;
            return false;
        }

        for(int i=0;i<rear;i++){
            arr[i]=arr[i+1];
        }

        rear--;
        return true;
    }
};

int main(){
    Queue q1;
    q1.enqeue(3);
    q1.enqeue(4);
    q1.dequeue();
    q1.enqeue(56);
    q1.enqeue(78);
    q1.enqeue(98);
    q1.dequeue();
    q1.display();
}