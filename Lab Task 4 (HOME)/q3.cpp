#include <iostream>
using namespace std;


void selectionSort(int *arr,int size){
    int minIndex=0;
    for(int i=0;i<size;i++){
        minIndex=i;
        for(int j=i;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }

}

void display(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int size=8;
    int arr[8]={3,6,2,8,4,9,4,6};
    selectionSort(arr,size);
    display(arr,size);

    return 0;
}