#include <bits/stdc++.h>

using namespace std;

string str;
int sum=0, mx=INT_MIN, mn=INT_MAX;

int isvowel(int start, int sz){
    int num=stoi(str.substr(start,sz));
}

void recur(string str){
    int cnt=0;
    for (char i:str){
        if ((int(i-'0'))%2==1){
            cnt++;
        }
    }
    if (str.size()>=3){
        for (int i=1;i<str.size()-1;i++){
            for (int j=i+1;j<str.size();j++){
                int a=stoi(str.substr(0,i));
                int b=stoi(str.substr(i,j-i));
                int c=stoi(str.substr(j,str.size()-j));
                sum+=cnt;
                recur(to_string(a+b+c));
                sum-=cnt;
            }
        }
    }
    else if (str.size()==2){
        int a=stoi(str.substr(0,1));
        int b=stoi(str.substr(1,1));
        sum+=cnt;
        recur(to_string(a+b));
        sum-=cnt;
    }
    else{
        sum+=cnt;
        if (sum>mx) mx=sum;
        if (sum<mn) mn=sum;
        sum-=cnt;
    }
};

int main()
{
    cin >> str;
    recur(str);
    cout << mn << " " << mx;
}