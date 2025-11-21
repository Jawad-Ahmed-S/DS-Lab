#include <iostream>
using namespace std;
struct Runner{
    string name;
    int time;
    void SetRunner(string n,int t){
        name=n;
        time=t;
    }
};
void merge(Runner array[],int left,int mid,int right){

    int l1 =mid-left+1;
    int l2 = right-mid;
    Runner * temp1 =new Runner[l1]; 
    Runner * temp2=new Runner[l2];
    
    for(int i=0;i<l1;i++){
        temp1[i]=array[left+i];
    }
    for(int i=0;i<l2;i++){
        temp2[i]=array[mid+1+i];
    }

    int i=0,j=0,k=left;
    while(i<l1 && j<l2){
        if(temp1[i].time<temp2[j].time){
            array[k]=temp1[i];
            i++;
        }
        else{
            array[k]=temp2[j];
            j++;
        }
        k++;
    }
    while(i<l1){
        array[k]=temp1[i];
        i++;
        k++;
    }
    while(j<l2){
        array[k]=temp2[j];
        j++;
        k++;
    }

}

void mergeSort(Runner array[],int left,int right){
    int mid;
    if(left<right){
        mid = left + (right-left)/2;
        
        mergeSort(array,left,mid);
        mergeSort(array,mid+1,right);
        
        merge(array,left,mid,right);
    }
}

int main() {
    int temptime;
    string tempname;
        Runner array[10];
    for(int i=0;i<10;i++){
        cout<<"Enter Runner and time";
        cin>>tempname>>temptime;
        array[i].SetRunner(tempname,temptime);
    
    }
    mergeSort(array,0,6);
    for(int i=0;i<6;i++){
        cout<<array[i].name<<" "<<array[i].time<<" "<<endl;
    }
    return 0;
}