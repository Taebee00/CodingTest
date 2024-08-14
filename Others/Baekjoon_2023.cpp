#include <bits/stdc++.h>

using namespace std;

int visitied[10]={0,}, N;
string num="";

bool IsSosu(string _num){
    int num=stoi(_num);
    bool flag=true;
    while(num!=0){
        if (num==2) break;
        if (num==1){
            flag=false;
            break;
        }
        for (int i=2;i*i<=num;i++){
            if (num%i==0){
                flag=false;
                break;
            }
        }
        if (flag==false) break;
        num/=10;
    }
    return flag;
}

void dfs(int sz){
    if (sz==N){
        if (IsSosu(num)&&num[0]!='0') cout << num << "\n";
        return;
    }
    for (int i=0;i<10;i++){
        string temp=num;
        temp+=(i+'0');
        if (IsSosu(temp)){
            num+=(i+'0');
            dfs(sz+1);
            num.pop_back();
        }
    }
}

int main()
{
    cin >> N;
    
    dfs(0);
}