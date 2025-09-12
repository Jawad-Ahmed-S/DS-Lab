#include <iostream>
using namespace std;

void addElement(int *&array,int &n,int val){
    int *temp=new int[(n)+1];
    for(int i=0;i<n;i++){
        temp[i]=array[i];
    }
    temp[n]=val;
    delete [] array;
    array=temp;
    cout<<"Added!"<<endl;
    n++;
}
void insertRoll(int *&array,int &n,int val){
    int *temp=new int[(n)+1];
    int i=0;
    for(i=0;i<n;i++){
        if(array[i]>val){
            break;
        }
        temp[i]=array[i];
    }
    temp[i]=val;
    for(;i<n;i++){
        temp[i+1]=array[i];
    }
    delete [] array;
    array=temp;
    cout<<"Added!"<<endl;
    n++;
}
int binarySearch(int array[],int n,int target){
    int start=0,end=n-1;
    int mid;
    while(end>=start){
        mid=(start+end)/2;
        if(array[mid]==target){
            return mid;
        }
        else if(target<array[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    addElement(array,n,target);
    return n;
}
void display(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
int main() {
    int n=0;
    int *array=new int[n];
    addElement(array,n,11);
    addElement(array,n,21);
    addElement(array,n,51);
    addElement(array,n,61);
    addElement(array,n,78);
    addElement(array,n,94);
    display(array,n);
    cout<<"\nFound at : "<<binarySearch(array,n,78);
    return 0;
}