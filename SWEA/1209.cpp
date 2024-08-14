#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    for (int i=1;i<=10;i++){
        cin >> TC;
        int arr[100][100], end, start;
        for (int j=0;j<100;j++){
            for (int k=0;k<100;k++){
                cin >> arr[j][k];
                if (arr[j][k]==2) start=k;
            }
        }
        for (int j=0;j<100;j++){
            for (int k=0;k<100;k++){
                cout << arr[j][k];
            }
            cout << "\n";
        }
        pair<int,int> temp={99,start};
        while(temp.first>=0){
            if (temp.second-1>=0&&arr[temp.first][temp.second-1]==1){
                while(temp.second-1>=0&&arr[temp.first][temp.second-1]==1){
                    temp.second--;
                }
            }
            else if (temp.second+1<100&&arr[temp.first][temp.second+1]==1){
                while(temp.second+1<100&&arr[temp.first][temp.second+1]==1){
                    temp.second++;
                }
            }
            temp.first--;
        }
        printf("#%d %d\n",TC,temp.second);
    }
}