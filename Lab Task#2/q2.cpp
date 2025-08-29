#include<iostream>
using namespace std;
int main(){
    int rows,col;
    cout<<"How many benches?";
    cin>>rows;
    cout<<"How many seats?";
    cin>>col;

    int **classRoom = new int*[rows];
    for(int i=0;i<rows;i++){
        classRoom[i] = new int[col];
        }
    
        cout<<"Seat Filling Started!"<<endl;
    while(true){
        char cont;
        cout<<"Do you want to occupy any seat? (y/n)\n";
        cin>>cont;
        if(cont=='n' || cont=='N')
            break;

            int x,y;
        cout<<"Enter the bench number"<<endl;
        cin>>x;
        cout<<"Enter the seat number"<<endl;
        cin>>y;

        if(x<0 || x>=rows || y<0 || y>=rows){
            cout<<"Out of bounds"<<endl;
            continue;
        }
        classRoom[rows][col] = 1;
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<classRoom[i][j]<<",";
        }
        cout<<endl;
    }
    
    for(int i=0;i<rows;i++){
        delete [] classRoom[i];
    }
    delete classRoom;
}