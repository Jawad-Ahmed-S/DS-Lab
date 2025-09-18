#include <iostream>
using namespace std;


int linearSearch(int *array,int size,int target){
    int flag=0;
    for(int i=0;i<size;i++){
        if(array[i]==target){
            cout<<"Found at index: "<<i+1<<endl;
            flag=1;
            return i+1;
        }
        flag=0;
    }
    if(flag==0){
        cout<<"Not found"<<endl;
    }
}
int main() {
    int size=5;
    int arr[5]={1,2,3,4,5};

    linearSearch(arr,size,3);
    return 0;
}