#include <iostream>
using namespace std;
bool isSafe(char **board,int row,int n,int col){

    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

//diagnol deal karo 
    
int i=row,j=col;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    i=row,j=col;
    while(i>=0 && j<n){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void nQueens(char **board,int row,int n){

    if(row==n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return;
}

    for(int j=0;j<n;j++){

        if(isSafe(board,row,n,j)){
            board[row][j] = 'Q';
            nQueens(board,row+1,n);
            board[row][j]='.';

        }
    }
}

int main() {

    int n=6;
    char **board = new char* [n];

    for(int i=0;i<n;i++){
        board[i] = new char[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='.';
        }
    }


    nQueens(board,0,n);

    return 0;
}