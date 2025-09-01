#include<iostream>
using namespace std;
class ExpenseCalculator{
int noMonths;
int *expense;
public:
    ExpenseCalculator(int n){
    this->noMonths=n;
    expense = new int[noMonths];
    }
    void InitializeArray(){
        cout<<"Initializing Array for "<<noMonths<<" months"<<endl;
        for(int i=0;i<noMonths;i++){
            cout<<"Enter expenses for Month "<<i+1<<": "<<endl;
            cin>>expense[i];
        }
    }
    void addNewExpense(){
        cout<<"Adding New Expense"<<endl;
        cout<<"Enter expenses for this month : "<<endl;
        int newExpense;
        cin>>newExpense;
        int *temp = new int[noMonths+1];
        for(int i=0;i<noMonths;i++){
            temp[i]=expense[i];
        }

            temp[noMonths]=newExpense;
            noMonths++;
        delete expense;
        expense = temp;
    }
    int totalExpense(){
        int total=0;
        for(int i=0;i<noMonths;i++){
            total+=expense[i];
        }
        return total;
    }
    void averageExpense(){
        cout<<"Average: "<<totalExpense()/noMonths<<endl;
    }
};
int main() {

     ExpenseCalculator e1(5);
     e1.InitializeArray();
     e1.addNewExpense();
     int tot = e1.totalExpense();
     cout<<"Total: "<<tot<<endl;
     e1.averageExpense();
 
    return 0;
}