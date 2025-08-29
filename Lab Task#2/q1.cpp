#include<iostream>
using namespace std;
int * arrayAllocation(int *array,int size){
    array = new int[size];
    for(int i=0;i<size;i++){
        array[i]=0;
    }
    return array;
    
};
int updateValues(int *array,int size){
    cout<<"Index?"<<endl;
    int idx;
    cin>>idx;
    cout<<"Value?"<<endl;
    int val;
    cin>>val;
    if(idx<0 || idx>=size){
        cout<<"Out of bounds"<<endl;
        return -1;
    }
    array[idx]=val;
    cout<<"Updated!"<<endl;
    return 0;
};
void display(int *array,int size){
        for(int i=0;i<size;i++){
            cout<<array[i]<<endl;
        }
    };
int main(){
    int *array;
    int size;
    cout<<"Size?"<<endl;
    cin>>size;
    array = arrayAllocation(array,size);
    int check =updateValues(array,size);
    if(check==-1){
        return 0;
    }
    display(array,size);


    delete[] array;
    return 0;
}