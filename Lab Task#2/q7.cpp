#include <iostream>
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
int main() {
    int noDepartments;
    int* noEmployees;
    int** salaries;

    cout << "Enter the number of Departments" << endl;
    cin >> noDepartments;

    noEmployees = new int[noDepartments];
    for (int i = 0; i < noDepartments; i++) {
        cout << "Enter number of Employees for Department " << i + 1 << ": " << endl;
        cin >> noEmployees[i];
    }

    cout << "Number of Employees initialized!" << endl;

    salaries = new int* [noDepartments];
    for (int i = 0; i < noDepartments; i++) {
        salaries[i] = new int[noEmployees[i]];
    }

    for (int i = 0; i < noDepartments; i++) {
        for (int j = 0; j < noEmployees[i]; j++) {
            cout << "Enter salaries of Department " << i + 1 << ": Employee " << j + 1 << endl;
            cin >> salaries[i][j];
        }
    }

    int* averagesalaries = new int[noDepartments]();  

    for (int i = 0; i < noDepartments; i++) {
        for (int j = 0; j < noEmployees[i]; j++) {
            averagesalaries[i] += salaries[i][j];
        }
        averagesalaries[i] /= noEmployees[i];  
    }

    int maxAverageSalary=max(averagesalaries,noDepartments);

    for (int i = 0; i < noDepartments; i++) {
        cout<<"Highest Salary of Department "<<i+1<<" :"<<maxValue(salaries[i],noEmployees[i])<<endl;
    }
    cout<<"Highest Average Salary Department No:"<<maxAverageSalary;
    delete[] averagesalaries;
    delete[] noEmployees;
    for (int i = 0; i < noDepartments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;

    return 0;
}