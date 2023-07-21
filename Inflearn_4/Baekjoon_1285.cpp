#include <bits/stdc++.h>

using namespace std;

int N,ret=0; int mp[20];

void find(int sz,int choice){
    int sum=0,cnt=0;
    for (int i=0;i<N;i++){
        cnt=0;
        for (int j=0;j<N;j++){
            if (mp[j]&(1<<i)){
                cnt++;
            }
        }
        sum+=(cnt<=N/2)?cnt:N-cnt;
    }
    for (int i=choice+1;i<N;i++){
        if (sz+1==2*N){
            mp[choice]=~(mp[choice]);
            if (sum<ret){
                ret=sum;
            }  
            return;
        }
        mp[i]=~(mp[i]);      
        find(sz+1,i);
    }
    mp[choice]=~(mp[choice]);
    if (sum<ret){
        ret=sum;
    }  
}

int main()
{   
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            char coin;
            cin >> coin;
            if (coin=='T'){
                mp[i]|=(1<<j);
                ret++;
            }          
        }
    }
    find(0,-1);
    cout << ret;
}