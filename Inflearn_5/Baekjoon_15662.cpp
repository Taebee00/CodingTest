#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,K,ret=0;
    vector<pair<int,int>> rotate_v;
    vector<pair<char,char>> two_six;
    char mp[1000][8];
    char temp_mp[1000][8];

    cin >> T;
    for (int i=0;i<T;i++){
        for (int j=0;j<8;j++){
            cin >> mp[i][j];
        }
    }

    cin >> K;
    for (int i=0;i<K;i++){
        pair<int,int> temp;
        cin >> temp.first >> temp.second;
        rotate_v.push_back({temp.first-1,temp.second});
    }

    for (int i=0;i<K;i++){
        two_six.clear();
        for (int j=0;j<T;j++){
            two_six.push_back({mp[j][2],mp[j][6]});
        }
        if (rotate_v[i].second==1){
            rotate(mp[rotate_v[i].first],mp[rotate_v[i].first]+7,mp[rotate_v[i].first]+8);
        }
        else{
            rotate(mp[rotate_v[i].first],mp[rotate_v[i].first]+1,mp[rotate_v[i].first]+8);
        }
        int lr=rotate_v[i].second;
        int temp_lr=lr;
        for (int j=rotate_v[i].first;j+1<T;j++){
            if (two_six[j].first!=two_six[j+1].second){
                if (temp_lr==1){
                    rotate(mp[j+1],mp[j+1]+1,mp[j+1]+8);
                }
                else{
                    rotate(mp[j+1],mp[j+1]+7,mp[j+1]+8);
                }
                temp_lr*=-1;
            }
            else{
                break;
            }
        }
        temp_lr=lr;
        for (int j=rotate_v[i].first;j>0;j--){
            if (two_six[j].second!=two_six[j-1].first){
                if (temp_lr==1){
                    rotate(mp[j-1],mp[j-1]+1,mp[j-1]+8);
                }
                else{
                    rotate(mp[j-1],mp[j-1]+7,mp[j-1]+8);
                }
                temp_lr*=-1;
            }
            else{
                break;
            }
        }
        // for (int i=0;i<T;i++){
        //     for (int j=0;j<8;j++){
        //         printf("%c",mp[i][j]);
        //     }
        // printf("\n");
        // }
    }

    for (int i=0;i<T;i++){
        if (mp[i][0]=='1'){
            ret++;
        }
    }

    

    cout << ret;
}