#include<iostream>
using namespace std;
class BankAccount{
    private:
    int balance;
    public:
    BankAccount(){
        this->balance=0;
    };
    BankAccount(int balance): balance(balance){};
    BankAccount(BankAccount *b){
        this->balance = b->balance;
    }
    int getBalance(){
        return this->balance;
    }
    void withdraw(int amount){
        if(amount<=balance && amount>0){
        balance-=amount;
        }else{
            cout<<"Invalid amount";
        }

    }
};

int main() {

     BankAccount account1;
     cout<<"Balance of account1 is : "<<account1.getBalance()<<"$"<<endl;
     BankAccount account2(1000);
     cout<<"Balance of account2 is : "<<account2.getBalance()<<"$"<<endl;
    BankAccount account3 = account2;
    account3.withdraw(200);
     cout<<"Balance of account2 is : "<<account2.getBalance()<<"$"<<endl;
     cout<<"Balance of account3 is : "<<account3.getBalance()<<"$"<<endl;
    return 0;
}