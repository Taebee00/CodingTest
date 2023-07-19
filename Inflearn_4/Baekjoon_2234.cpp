#include <bits/stdc++.h>

using namespace std;

int N,M,sz;
int mp[50][50];
int visitied[50][50]={0,};

int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

void init(){
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            visitied[i][j]=0;
        }
    }
}

void dfs(int y,int x){
    sz++;
    visitied[y][x]=1;
    for (int i=0;i<4;i++){
        if (!(mp[y][x]&(1<<i))){
            if (x+dx[i]>=0&&y+dy[i]>=0&&x+dx[i]<N&&y+dy[i]<M&&!visitied[y+dy[i]][x+dx[i]]){
                dfs(y+dy[i],x+dx[i]);
            }
        }
    }
}

int main()
{
    int one=0,two=0,three=0;
    cin >> N >> M;
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j];
        }
    }

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            if (!visitied[i][j])
            {
                one++;
                sz=0;
                dfs(i,j);
                if (sz>two){
                    two=sz;
                }
            }
        }
    }

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<4;k++){
                init();
                int temp=mp[i][j];
                mp[i][j]&=~(1<<k);
                sz=0;
                dfs(i,j);
                if (sz>three){
                    three=sz;
                }
                mp[i][j]=temp;
            }            
        }
    }

    cout << one << "\n"<< two << "\n" << three;
}