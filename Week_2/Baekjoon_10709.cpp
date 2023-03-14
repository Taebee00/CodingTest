#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    string mp[100];
    cin >> h >> w;
    for (int i=0;i<h;i++){
        cin >> mp[i];
    }
    for (int i=0;i<h;i++){
        int flag=0,cnt=0;
        for (int j=0;j<w;j++){
            if (mp[i][j]=='c'){
                flag=1;
                cnt=0;
                cout << '0' << " ";
            }
            else if (flag){
                cnt++;
                cout << cnt << " ";
            }
            else{
                cout << "-1" << " ";
            }
        }
        cout << "\n";
    }
}