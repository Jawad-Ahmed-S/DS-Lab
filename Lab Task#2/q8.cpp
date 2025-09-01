#include<iostream>
using namespace std;
int maxValue(int array[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}
int max(int array[],int n){
    int max=0,maxIndx;
    for(int i=0;i<n;i++){
        if(array[i]>max){
            max=array[i];
            maxIndx=i;
        }
    }
    return maxIndx+1;
}
int min(int array[],int n){
    int min=99999,minIndx;
    for(int i=0;i<n;i++){
        if(array[i]<min){
            min=array[i];
            minIndx=i;
        }
    }
    return minIndx+1;
}
int minValue(int array[],int n){
    int min=99999;
    for(int i=0;i<n;i++){
        if(array[i]<min){
            min=array[i];
        }
    }
    return min;
}
int main(){
    int **temprature;
    int m;
    int n;

    cout<<"Enter no of Days";
    cin>>n;
    cout<<"Enter no of times a day";
    cin>>m;

    temprature = new int*[n];
    for(int i=0;i<n;i++){
        temprature[i]=new int[m];
    }

    cout<<"No of days and times initialized!"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter temprature for Day : "<<i+1<<" Time :"<<j+1<<endl;
            cin>>temprature[i][j];
        }
    }
    int* averageTemprature = new int[n];  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            averageTemprature[i] += temprature[i][j];
        }
        averageTemprature[i] /= m;  
    }
    
    for(int i=0;i<n;i++){
        cout<<"Average temprature on Day "<<i+1<<" is "<<averageTemprature[i]<<" C"<<endl;
    }

    cout<<"Coldest day was day"<<min(averageTemprature,n)<<"with "<<minValue(averageTemprature,n)<<" C"<<endl;
    cout<<"Hottest day was day"<<max(averageTemprature,n)<<"with "<<maxValue(averageTemprature,n)<<" C"<<endl;

}