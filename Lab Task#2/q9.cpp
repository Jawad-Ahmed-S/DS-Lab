#include<iostream>
using namespace std;
void display(int rows,int cols,int **array){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"end of display\n";
}
int main(){
    int rows;
    int cols;
    cout<<"Enter rows : ";
    cin>>rows;
    cout<<"Enter Cols : ";
    cin>>cols;

    int **matrix = new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }
    
    cout<<"Initializing Sparse Matrix"<<endl;
    int noNonZero=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"Enter element row "<<i+1<<" col "<<j+1<<" : ";
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                noNonZero++;
            }
        }
    }

    display(rows,cols,matrix);

    cout<<"Compressing the Sparse Matrix"<<endl;
    int **compressedMatrix = new int*[noNonZero];
    for(int i=0;i<noNonZero;i++){
        compressedMatrix[i] = new int[3];
    }
int k=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
                if(matrix[i][j]!=0){
                    compressedMatrix[k][0]=i;
                    compressedMatrix[k][1]=j;
                    compressedMatrix[k][2]=matrix[i][j];
                    k++;
                }
        }
    }
    display(noNonZero,3,compressedMatrix);
}