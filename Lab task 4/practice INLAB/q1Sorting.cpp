#include <iostream>
using namespace std;
void bubbleSort(int array[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(array[i]>array[j]){
                swap(array[i],array[j]);
            }
        }
    }
}
int main() {
    int n=10;
    int array[10]={5,1,3,6,2,9,7,4,8,10};
    cout<<"Unsorted: "<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\nSorted: "<<endl;
    bubbleSort(array,10);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }

    return 0;
}