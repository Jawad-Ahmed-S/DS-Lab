#include <iostream>
using namespace std;

    class Stack{
        int max=100;
        int array[100];
        int top;
        public:
        Stack(){
            top=-1;
        }
        void push(int num){
            if(top>=(max-1)){

                cout<<"Stack Overflow!"<<endl;
                return;
            }
            else{

                array[++top]=num;
                cout<<"Element Added : "<<num<<endl;
            }
        }
        void pop(){
            if(top<0){

                cout<<"Stack Underflow!"<<endl;
                return;
            }
            else{
                
                cout<<"Element Removed : "<<array[top--]<<endl;
            }
        }
        int peek(){
            if(top<0){
                cout<<"Stack is empty! "<<endl;
                return 0;
            }
            else{
                return array[top];
            }
        }
        bool isEmpty(){
            return (top<0);
                
        }

};
int main() {
    
    Stack s1;
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