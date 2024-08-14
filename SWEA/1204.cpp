#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=0;i<TC;i++){
        int n, arr[101]={0,}, mx=0, mx_idx=0;
        cin >> n;
        for (int i=0;i<1000;i++){
            int temp;
            cin >> temp;
            arr[temp]++;
            if (arr[temp]>=mx){
                if (mx==arr[temp]&&temp<mx_idx) continue;
                mx=arr[temp];
                mx_idx=temp;
            }
        }
        printf("#%d %d\n",n,mx_idx);
    }
}