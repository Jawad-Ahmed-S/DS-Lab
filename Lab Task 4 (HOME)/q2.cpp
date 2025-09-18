#include <iostream>
using namespace std;

void bubbleSort(int *arr,int size){
    for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(arr[i]<arr[j]){
            swap(arr[i],arr[j]);
        }
    }
    }
}
void display(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int size =5;
    int arr[5]={4,2,5,1,6};
    bubbleSort(arr,size);
    display(arr,size);
    return 0;
}