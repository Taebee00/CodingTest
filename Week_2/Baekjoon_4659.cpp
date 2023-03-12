#include <bits/stdc++.h>
using namespace std;

int flag_1=0,flag_2=1,flag_3=1;
string aeiou="aeiou";
char moja[21]={'j',};

int main(){
    string str;
    while(true){
        cin >> str;
        if (str=="end"){
            break;
        }
        for (int i=0;i<str.length();i++){
            for (auto &j:aeiou){
                if (str[i]==j){
                    flag_1=1;
                    moja[i]='m';
                    break;
                }
            }
        }
        if (str.length()>=3){
            for (int i=0;i<str.length()-2;i++){
                if (moja[i]==moja[i+1]&&moja[i+1]==moja[i+2]){
                    flag_2=0;
                    break;
                }
            }
        }
        if (str.length()>=2){
            for (int i=0;i<str.length()-1;i++){
                if (str[i]==str[i+1]){
                    if (str[i]!='e'&&str[i]!='o'){
                        flag_3=0;
                        break;
                    }
                }
            }
        }
        if (flag_1&&flag_2&&flag_3){  
            cout << "<" << str << "> " << "is acceptable.\n";
        }
        else{
            cout << "<" << str << "> " << "is not acceptable.\n";
        }
        flag_1=0;flag_2=1;flag_3=1;
        fill(moja,moja+20,'j');
    }
}