#include <bits/stdc++.h>

using namespace std;

int N,M,ret=INT_MAX,channel;
int arr[10];

void cal(){
    //cout << sz;
    for (int i=0;i<=1000000;i++){
        int num=i,flag=0,cnt=0;
        do{
            if (!arr[num%10]){
                flag=1;
                break;
            }
            num/=10;
            cnt++;
        }while(num);
        if (!flag){
            ret=min(cnt+abs(i-N),ret);
            //printf("%d - %d\n",i, ret);
        }
    }
}

int main()
{
    fill(arr,arr+10,1);
    cin >> N >> M;
    for (int i=0;i<M;i++){
        int temp;
        cin >> temp;
        arr[temp]=0;
    }
    cal();
    if (abs(100-N)<ret){
        ret=abs(100-N);
    }
    cout << ret;
}