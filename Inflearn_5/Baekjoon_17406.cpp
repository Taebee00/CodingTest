#include <bits/stdc++.h>

using namespace std;

int N, M, K, mp[51][51], temp_mp[51][51], ret=INT_MAX;
vector<vector<int>> v;
vector<int> choose_v;
int visitied[10]={0,};
int dy[4]={1,0,-1,0}, dx[4]={0,1,0,-1};

void rotate(int y,int x,int sz){
    for (int i=1;i<=sz;i++){

        int start_y=y-i;
        int start_x=x-i; 
        int start_val=temp_mp[start_y][start_x];
        int temp_y=start_y;
        int temp_x=start_x;

        for (int j=0;j<4;j++){
            int rotate_flag=i*2;
            while(rotate_flag--){
                // printf("%d,%d ",temp_y,temp_x);
                temp_mp[temp_y][temp_x]=temp_mp[temp_y+dy[j]][temp_x+dx[j]];
                temp_y+=dy[j];
                temp_x+=dx[j];
            }
            //printf("\n");
        }
        temp_mp[start_y][start_x+1]=start_val;
    }
}

void choose(int sz,vector<int> &_choose_v){
    // printf("sz: %d\n",sz);
    // for (int&i:_choose_v){
    //     printf("%d ",i);
    // }
    // printf("\n");
    // printf("%d %d\n",visitied[0],visitied[1]);
    if (sz==K){
        for (int i=1;i<=N;i++){
            for (int j=1;j<=M;j++){
                temp_mp[i][j]=mp[i][j];
            }
        }
        for (int i=0;i<10;i++){
            visitied[i]=0;
        }
        for (int&i:_choose_v){
            printf("%d ",i);
            rotate(v[i][0],v[i][1],v[i][2]);
            for (int j=1;j<=N;j++){
                int sum=0;
                for (int k=1;k<=M;k++){
                    sum+=temp_mp[j][k];
                }
                if (sum<ret){
                    ret=sum;
                }
            }
        }
        printf("\n");
        return;
    }
    
    for (int i=0;i<K;i++){
        if (find(_choose_v.begin(),_choose_v.end(),i)==_choose_v.end()){
            _choose_v.push_back(i);
            visitied[i]=1;
            choose(sz+1,_choose_v);
            visitied[i]=0;
            _choose_v.pop_back();    
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for (int i=1;i<N+1;i++){
        for (int j=1;j<M+1;j++){
            cin >> mp[i][j];
        }
    }

    for (int i=0;i<K;i++){
        vector<int> temp_v;
        for (int j=0;j<3;j++){
            int temp;
            cin >> temp;
            temp_v.push_back(temp);
        }
        v.push_back(temp_v);
    }

    choose(0,choose_v);
    // for (int i=1;i<N+1;i++){
    //     for (int j=1;j<M+1;j++){
    //         printf("%d ",temp_mp[i][j]);
    //     }
    //     printf("\n");
    // }
    cout << ret;
}