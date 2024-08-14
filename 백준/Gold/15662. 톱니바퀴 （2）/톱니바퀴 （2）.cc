#include <bits/stdc++.h>

using namespace std;

int T, K, answer=0;
vector<string> gear_v;
vector<pair<int,int>> rotate_v;

int main()
{
    cin >> T;

    for (int i=0;i<T;i++){
        string temp;
        cin >> temp;
        gear_v.push_back(temp);
    }

    cin >> K;

    for (int i=0;i<K;i++){
        int gear, dir;
        cin >> gear >> dir;
        rotate_v.push_back({gear-1,dir});
    }
    int cnt=1;
    for (auto i:rotate_v){
        int dir=i.second;
        int rotate_arr[1001]={0,};
        rotate_arr[i.first]=i.second;  
        for (int j=i.first;j>0;j--){
            if (gear_v[j][6]!=gear_v[j-1][2]){
                rotate_arr[j-1]=rotate_arr[j]==1?-1:1;
            }
            else break;
        }
        dir=i.second;
        for (int j=i.first;j<T-1;j++){
            if (gear_v[j][2]!=gear_v[j+1][6]){
                rotate_arr[j+1]=rotate_arr[j]==1?-1:1;
            }
            else break;
        }
        for (int j=0;j<T;j++){
            if (rotate_arr[j]==1) rotate(gear_v[j].begin(),gear_v[j].end()-1,gear_v[j].end());
            else if (rotate_arr[j]==-1) rotate(gear_v[j].begin(),gear_v[j].begin()+1,gear_v[j].end());
        }
    }
    for (auto i:gear_v){
        if (i[0]=='1') answer++;
    }
    cout << answer;
}