#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

int recur(int day,int money,int mid)
{
    printf("%d %d %d\n",day,v[day],money);
    if (day==N-1){
        return 0;
    }
    if (v[day]<money){
        recur(day+1,mid,mid);
    }
    else{
        recur(day+1,mid,mid);
        recur(day+1,money-v[day],mid);
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int low=0, high=100000;
    // while(low<=high){
    //     int mid=(low+high)/2;
    //     recur(0,true,mid);
    // }
    recur(0,0,500);
}