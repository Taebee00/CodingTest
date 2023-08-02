#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, cnt=0, arr[100004],visitied[100004]={0,};
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> arr[i];
    }
    for (int i=0;i<N;i++){
        visitied[arr[i]]=i+1;
        cnt++;
        for (int j=i+1;j<N;j++){
            if (visitied[arr[j]]==i+1){
                break;
            }
            visitied[arr[j]]=i+1;
            cnt++;
        }
    }
    cout << cnt;
}