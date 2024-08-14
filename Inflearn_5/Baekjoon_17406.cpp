#include <bits/stdc++.h>

using namespace std;

struct rot{
    int r;
    int c;
    int s;
};

int N, M, K, answer=INT_MAX, arr[50][50], temp_arr[50][50];
vector<struct rot> v;

void circle(int sy,int sx,int sz){
    int sv=temp_arr[sy][sx];
    int y=sy; int x=sx;
    while(y<sy+sz){
        temp_arr[y][x]=temp_arr[y+1][x];
        y++;
    }
    while(x<sx+sz){
        temp_arr[y][x]=temp_arr[y][x+1];
        x++;
    }
    while(y>sy){
        temp_arr[y][x]=temp_arr[y-1][x];
        y--;
    }
    while(x>sx){
        temp_arr[y][x]=temp_arr[y][x-1];
        x--;
    }
    temp_arr[sy][sx+1]=sv;
}

void cal()
{
    memcpy(temp_arr,arr,sizeof(arr));
    for (auto i:v){
        for (int j=1;j<=i.s;j++){
            circle(i.r-j,i.c-j,j*2);
        }
    }
    int mn=INT_MAX;
    for (int i=0;i<N;i++){
        int sum=0;
        for (int j=0;j<M;j++){
            sum+=temp_arr[i][j];
        }
        mn=min(sum,mn);
    }
    answer=min(answer,mn);
}

void permutation(int depth){
    if (depth==v.size()){
        cal();
        return;
    }
    for (int i=depth;i<v.size();i++){
        swap(v[i],v[depth]);
        permutation(depth+1);
        swap(v[i],v[depth]);
    }
}

int main()
{
    cin >> N >> M >> K;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0;i<K;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a-1,b-1,c});
    }
    permutation(0);
    cout << answer;
}