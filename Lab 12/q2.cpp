#include <iostream>
using namespace std;

#define size 256

void rabinKarp(string text,string pattern, int q){
    int n= text.length();
    int m= pattern.length();

    if(m == 0 || m>n){
        return;
    }

    int p=0,t=0,h=0;

    for(int i=0;i<m-1;i++){
        h = (h*size)%q;
    }

    for(int i=0;i<m;i++){
        t = (t*size + text[i])%size;
        p = (p*size + pattern[i])%size;
    }

    for(int i=0;i<n-m;i++){
        if(p==t){
            bool match = true;
            for(int j=0;j<m;j++){
                if(text[i+j]!=pattern[j]){
                    match = false;
                    break;
                }
            }
        if (match) {
                cout << "Pattern found : " << i << endl;
            }


        }
    if(i<n-m){
        t = (size * (t-text[i])*h) + text[i+m]%q;
    }        
    if(t<0){
        t = t+q;
    }

    }


}
int main() {
    string text ="Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";
    rabinKarp(text,pattern,11);
    return 0;
}