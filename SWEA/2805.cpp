#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=0;i<TC;i++){
        int N; char arr[50][50];
        cin >> N;
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                cin >> arr[j][k];
            }
        }
        int sum=0;
        for (int j=0;j<N;j++){
            int st=abs((N/2)-j);
            for (int k=st;k<N-st;k++){
                sum+=(arr[j][k]-'0');
            }
        }
        printf("#%d %d\n",i+1,sum);
    }
}