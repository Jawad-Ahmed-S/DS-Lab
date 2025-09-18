#include <iostream>
using namespace std;
int interpolitanSearch(int *arr,int start,int end,int target){

    int pos = start + ((target - arr[start])*(end-start))/(arr[end]-arr[start]);
    if(end<start){
        return -1;
    }
    if(arr[pos]==target){
        return pos;
    }
    else if(arr[pos]<target){
       return interpolitanSearch(arr,pos+1,end,target);
    }
    else{
        
       return interpolitanSearch(arr,start,pos-1,target);
    }
}

int main() {
    int size=9;
    int arr[9]={15,25,35,45,55,65,75,85,95};
    int found = interpolitanSearch(arr,0,size,35);
     if(found!=-1){
        cout<<"\nFound at: "<<found+1<<endl;    
    }
    else{
        cout<<"Element not found"<<endl;
    }
   
    return 0;
}