#include <bits/stdc++.h>

using namespace std;

int T,N,mn=INT_MAX;
int mp[100]={0,};
vector<int> v;
vector<int> choose_v;

int cal(){
    int sum=0;
    for (int i=0;i<2;i++){
        for (int j=i+1;j<3;j++){
            int num=v[choose_v[i]]^v[choose_v[j]];
            
            for (int k=0;k<4;k++){
                if ((num&(1<<k))){
                    sum++;
                }
            }
        }
    }
    return sum;
}

void mbti(int sz,int choice){
    if (sz==3){
        mn=min(cal(),mn);
    }
    for (int i=choice+1;i<v.size();i++){
        choose_v.push_back(i);
        mbti(sz+1,i);
        choose_v.pop_back();
    }
}

int main()
{
    cin >> T;
    for (int i=0;i<T;i++){
        mn=INT_MAX;
        string str;
        cin >> N;
        v.clear();
        choose_v.clear();
        int flag=0;
        for (int j=0;j<N;j++){
            cin >> str;
            int num=0;
            if (str[0]=='E'){
                num|=1<<3;
            }
            if (str[1]=='S'){
                num|=1<<2;
            }
            if (str[2]=='T'){
                num|=1<<1;
            }
            if (str[3]=='J'){
                num|=1<<0;
            }
            if (mp[num]<=2){
                mp[num]+=1;
                v.push_back(num);
            }
            else{
                flag=1;
                break;
            }
        }
        if (!flag){
            mbti(0,-1);
            cout << mn << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
}