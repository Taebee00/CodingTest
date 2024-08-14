#include <bits/stdc++.h>

using namespace std;

int N,K,mx=0;
string str[50];
int bin=(1<<'a'-'a')|(1<<'n'-'a')|(1<<'t'-'a')|(1<<'i'-'a')|(1<<'c'-'a');

void find(int num,int left,int choice)
{   
    if (left==0){
        int cnt=0;
        for (int i=0;i<N;i++){
            int flag=0;
            for (int j=0;j<str[i].length();j++){
                if (!(bin&(1<<(str[i][j]-'a')))){
                    flag=1;
                    break;
                }
            }
            if (!flag){
                cnt++;
            }
        }
        if (cnt>mx){
            mx=cnt;
        }
    }
    for (int i=choice+1;i<num;i++){
        if (i+'a'=='a'||i+'a'=='n'||i+'a'=='t'||i+'a'=='c'||i+'a'=='i'){
            continue;
        }
        bin|=1<<i;
        find(num,left-1,i);
    }
    bin&=~(1<<choice);
    return;
}

int main()
{  
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> str[i];
    }
    if (K<5){
        cout << '0';
        return 0;
    }
    find(26,K-5,-1);
    cout << mx;
}