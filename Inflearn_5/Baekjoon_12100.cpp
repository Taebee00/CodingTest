#include <bits/stdc++.h>

using namespace std;

int N, mp[24][24],temp_mp[24][24],visitied[24][24]={0,}, mx=0;
vector<int> v;

void cal(){
    int cnt=0;
    for (int&i:v){
        cnt++;
        //왼쪽
        if (i==0){
            for (int j=0;j<N;j++){
                for (int k=1;k<N;k++){
                    int l=k;
                    while(!temp_mp[j][l-1]&&l-1>=0){
                        temp_mp[j][l-1]=temp_mp[j][l];
                        temp_mp[j][l]=0;
                        l--;
                    }
                    if (visitied[j][l-1]!=cnt&&temp_mp[j][l-1]==temp_mp[j][l]&&l<N){
                        temp_mp[j][l-1]*=2;
                        visitied[j][l-1]=cnt;
                        temp_mp[j][l]=0;
                    }
                }
            }
        }
        //왼쪽
        else if (i==1){
            for (int j=0;j<N;j++){
                for (int k=N-2;k>=0;k--){
                    int l=k;
                    while(!temp_mp[j][l+1]&&l>=0){
                        temp_mp[j][l+1]=temp_mp[j][l];
                        temp_mp[j][l]=0;
                        l--;
                    }
                    if (visitied[j][l+1]!=cnt&&temp_mp[j][l+1]==temp_mp[j][l]&&l>=0){
                        temp_mp[j][l+1]*=2;
                        visitied[j][l+1]=cnt;
                        temp_mp[j][l]=0;
                    }
                }
            }
        }
        //위쪽
        else if (i==2){
            for (int j=0;j<N;j++){
                for (int k=1;k<N;k++){
                    int l=k;
                    while(!temp_mp[l-1][j]&&l<N){
                        temp_mp[l-1][j]=temp_mp[l][j];
                        temp_mp[l][j]=0;
                        l++;
                    }
                    if (visitied[l-1][j]!=cnt&&temp_mp[l-1][j]==temp_mp[l][j]&&l<N){
                        temp_mp[l-1][j]*=2;
                        visitied[l-1][j]=cnt;
                        temp_mp[l][l]=0;
                    }
                }
            }
        }
        else{
            for (int j=0;j<N;j++){
                for (int k=N-2;k>=0;k--){
                    int l=k;
                    while(!temp_mp[l+1][j]&&l>=0){
                        temp_mp[l+1][j]=temp_mp[l][j];
                        temp_mp[l][j]=0;
                        l--;
                    }
                    if (visitied[l+1][j]!=cnt&&temp_mp[l+1][j]==temp_mp[l][j]&&l>=0){
                        temp_mp[l+1][j]*=2;
                        visitied[l+1][j]=cnt;
                        temp_mp[l][l]=0;
                    }
                }
            }
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (temp_mp[i][j]>mx){
                mx=temp_mp[i][j];
            }
        }
    }
}

void choose(int sz,int choice){
    if (sz==5){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                temp_mp[i][j]=mp[i][j];
                visitied[i][j]=0;
            }
        }
        cal();
        return;
    }
    for (int i=0;i<4;i++){
        v.push_back(i);
        choose(sz+1,i);
        if (!v.empty()){
            v.pop_back();
        }
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
        }
    }
    choose(0,0);
    cout << mx;
}