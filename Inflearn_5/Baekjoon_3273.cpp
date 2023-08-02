#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, x, cnt=0, arr[100000];
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr,arr+N);
    for (int i=0;i<N;i++){
        int j=i+1;
        while(j<N&&arr[j]<x-arr[i]){
            j++;
        }
        if (j<N&&arr[j]==x-arr[i]){
            cnt++;
        }
    }
    cout << cnt;
}