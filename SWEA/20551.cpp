#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int arr[3], answer=0;
        for (int j=0;j<3;j++) cin >> arr[j];
        for (int j=1;j>=0;j--){
            if (arr[j]<arr[j+1]) continue;
            int num=arr[j]-(arr[j+1]-1);
            arr[j]=arr[j+1]-1;
            if (arr[j]<1){
                answer=-1;
                break;
            }
            answer+=num;
        }
        printf("#%d %d\n",i+1,answer);
    }
}