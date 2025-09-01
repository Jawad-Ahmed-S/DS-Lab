#include<iostream>
using namespace std;
class SafePointers{
    int *ptr;
    public:
    SafePointers(){
        ptr = new int;
    }
    ~SafePointers(){
        if(ptr!=nullptr){
            delete ptr;
            ptr = nullptr;
        }
    }
    void setValue(int value){
        *ptr = value;
    }
    int getValue(){
        return *ptr;
    }
    void release(){
        if(ptr!=nullptr){
            delete ptr;
            ptr=nullptr;
        }
    }
};
int main(){
    
    SafePointers SP[5];
    int val;
    for(int i=0;i<5;i++){
        cout<<"Enter Value for instance : "<<i+1<<" ";
        cin>>val;
        SP[i].setValue(val);
    }
    
    for(int i=0;i<5;i++){
        cout<<"Value :"<<SP[i].getValue()<<endl;

    }
    
    for(int i=0;i<5;i++){
        SP[i].release();
    }
    cout<<"All Instances' pointers Manually released"<<endl;
    


}