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

int binarySearch(int *arr,int start,int end,int target){

    int mid = (start+end)/2;
    if(end<start){
        return -1;
    }
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
       return binarySearch(arr,mid+1,end,target);
    }
    else{
        
       return binarySearch(arr,start,mid-1,target);
    }
}
int main() {
    int size=8;
    int arr[8]={3,6,2,8,4,9,4,6};
    selectionSort(arr,size);
    display(arr,size);
    int index = binarySearch(arr,0,size-1,8);
    if(index!=-1){
        cout<<"\nFound at: "<<index+1<<endl;    
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}