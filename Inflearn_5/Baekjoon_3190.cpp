#include <bits/stdc++.h>

using namespace std;

int N, K, L, arr[100][100]={0,}, dir_arr[100][100]={0,}, visitied[100][100]={0,};
int dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};
char tm_arr[10001]={0,};

int main()
{
    cin >> N >> K;

    for (int i=0;i<K;i++){
        int a,b;
        cin >> a >> b;
        arr[a-1][b-1]=1;
    }

    cin >> L;

    for (int i=0;i<L;i++){
        int tm; char dir;
        cin >> tm >> dir;
        tm_arr[tm]=dir;
    }

    int hy=0, hx=0, ty=0, tx=0, tm=0, dir=0;
    visitied[0][0]=1;

    while(1){
        tm++;
        dir_arr[hy][hx]=dir;
        hy+=dy[dir]; hx+=dx[dir];
        if (hy<0||hx<0||hy>=N||hx>=N||visitied[hy][hx]){
            break;
        }
        visitied[hy][hx]=1;
        if (arr[hy][hx]) arr[hy][hx]=0;
        else{
            visitied[ty][tx]=0;
            int temp_dir=dir_arr[ty][tx];
            ty=ty+dy[temp_dir];
            tx=tx+dx[temp_dir];
        }
        if (tm<=10000&&tm_arr[tm]=='L'){
            dir=(dir+3)%4;
        }
        else if (tm_arr[tm]=='D') dir=(dir+1)%4;
    }

    cout << tm;
}