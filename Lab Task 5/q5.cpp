#include <iostream>
using namespace std;

bool isSafe(int board[9][9],int row,int col,int digit){
    for(int i=0;i<9;i++){
        if(board[row][i]==digit){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(board[i][col]==digit){
            return false;
        }
    }

    int girdStartingCol = (col/3)*3;
    int girdStartingRow = (row/3)*3;

    for(int i=girdStartingRow;i<girdStartingRow+3;i++){
        for(int j=girdStartingCol;j<girdStartingCol+3;j++){
            if(board[i][j]==digit){
                return false;
            }
        }
    }
    return true;
}

bool helperFunction(int board[9][9],int row,int col){

    if(row==9){
        return true;
    }
    int nextRow = row,nextCol = col+1;
    if(nextCol==9){
        nextCol=0;
        nextRow=row+1;
    }

    if(board[row][col]!=0){
        return helperFunction(board,nextRow,nextCol);
    }

    for(int digit=1;digit<=9;digit++){
        if(isSafe(board,row,col,digit)){
            board[row][col] =digit;
            if(helperFunction(board,nextRow,nextCol)){
                return true;
            }
            board[row][col] =0;
        }
    }
    return false;

}

    void sodukoSolver(int board[9][9],int row,int col){
            helperFunction(board,row,col);
    }
int main() {
    

    int board[9][9] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},
    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},
    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};

    
    sodukoSolver(board,0,0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}