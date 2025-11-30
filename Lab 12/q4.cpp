#include <iostream>
#include <vector>
using namespace std;

void computeLPS(string pattern,vector<int> &LPS){
    int m=pattern.length();
    LPS[0]=0;
    int len =0;
    int i=1;

    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            LPS[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len = LPS[len-1];
            }
            else{
                LPS[i]=0;
                i++;
            }
        }

        i++;
    }
}
void KMP(string text,string pattern){

    
    int n = text.length();
    int m= pattern.length();
    vector <int> LPS;
    computeLPS(pattern,LPS);
    cout<<"LPS: "<<endl;
    for(int i=0;i<m;i++){
        cout<<LPS[i]<<" ";
    }
    int i=0,j=0;

    while(i<n){
        if(pattern[j]==text[i]){
            i++;j++;
        }

        if(j==m){
            cout<<"found at "<<i-j<<endl;
            j = LPS[j-1];
        }
        else if(i<n && pattern[j]!= text[i]){
            if(j!=0){
                j = LPS[j-1];
            }
            else{
                i++;
            }
        }

    }


}
int main() {
    string text = "ababababc";
    string pattern = "abab";
    KMP(text,pattern);
    return 0;
}