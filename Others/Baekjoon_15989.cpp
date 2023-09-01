#include <bits/stdc++.h>

using namespace std;

int T,N,sum=0,cnt=0;
vector<int> v;

void count(int num,int choice){
    if (sum==num){
        cnt++;
    }
    else if (sum>num){
        return;
    }
    for (int i=choice;i<=3;i++){
        sum+=i;
        count(num,i);
        sum-=i;
    }
}

int main()
{
    cin >> T;
    for (int i=0;i<T;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for (int &i:v){
        sum=0, cnt=0;
        count(i,1);
        printf("%d\n",cnt);
    }
}