#include<iostream>
using namespace std;


int bruteForce(string text,string pattern){
    int n = text.length();
    int m = pattern.length();
    int count=0;

    for(int i=0;i<n-m;i++){

        int j=0;
        while(j<m && text[i+j] == pattern[j]){
            j++;
            count++;
        }
        if(j==m){
            cout<<"Pattern Found! : "<<i<<endl;

        }
    }
    return count;
}
int main(){
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int comparisons = bruteForce(text,pattern);
    cout<<"Total Comparisons made: "<<comparisons<<endl;
}