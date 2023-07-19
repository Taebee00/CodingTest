#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char except[5]={'a','n','t','i','c'};

    int N, K, mpcnt=0, res=0;
    string words[50];
    map<char,int> mp;
    cin >> N >> K;
    for (int i=0;i<N;i++){
        cin >> words[i];
        for (int j=4;j<words[i].length()-4;j++){
            if (!mp[words[i][j]]&&find(begin(except),end(except),words[i][j])==end(except)){
                mp[words[i][j]]=mpcnt++;
            }
        }  
    }
    for (int i=0;i<(1<<mpcnt);i++){
        int cnt=0;
        for (int j=0;j<mpcnt;j++){
            if (i&(1<<j)){
                cnt++;
            }
            if (cnt>K-5){
                break;
            }
        }
        int readcnt=0;
        if (cnt==K-5){
            for(int j=0;j<N;j++){
                int flag=0;
                for (int k=0;k<words[j].length();k++){
                    if (!(i&(1<<mp[words[j][k]]))&&find(begin(except),end(except),words[j][k])==end(except)){
                        flag=1;
                        break;
                    }
                }
                if (!flag){
                    readcnt++;
                }
            }
        }
        if (readcnt>res){
            res=readcnt;
        }       
    }
    cout<<res;
}