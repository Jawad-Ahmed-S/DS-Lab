#include<iostream>
using namespace std;
class Exam{
    char *name;
    string examDate;
    int score;
    int namelen;
    public:
    Exam(){
        examDate="0/0/0";
        score=0;
        namelen=0;
    }
    Exam(char *Name,int len,string date,int score){
        namelen=len;
        name = new char[namelen];
        for(int i=0;i<namelen;i++){
            this->name[i]=Name[i];
        }
        examDate=date;
        this->score=score;
    }
    void setName(char* Name, int len){
    for(int i=0;i<len && i<namelen;i++){
        this->name[i] = Name[i];
    }
}

    void setDate(string date){
        examDate=date;
    }
    void setScore(int score){
        this->score=score;
    }
    void printDetails(){
        cout<<"Name : ";
        for(int i=0;i<namelen;i++){
            cout<<name[i];
        }
        cout<<"Date : "<<examDate<<endl;
        cout<<"Score :"<<score<<endl;
    }

};
int main() {
    
    Exam ex1((char*)"Jawad",5,"4/5/25",50);
    ex1.printDetails();
    Exam ex2 =ex1;
    ex2.printDetails();
    ex2.setName((char*)"Ahmed",5);
    ex2.printDetails();
    ex1.printDetails();
 
    return 0;
}