#include <bits/stdc++.h>

using namespace std;

int N, K, L, mp[100][100]={0,},dir=0,snake_x=0,snake_y=0,dir_mp[100][100]={0,};
int dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};
queue<pair<int,char>> q;
pair<int,int> tail={0,0};

int snake(){
    int cnt=0;
    dir=0;
    mp[0][0]=1;
    while(1)
    {
        // printf("%d\n",cnt);
        // for (int i=0;i<N;i++){
        //     for (int j=0;j<N;j++){
        //         printf("%d ",mp[i][j]);
        //     }
        //     printf("\n");
        // }
        dir_mp[snake_y][snake_x]=dir;
        snake_y+=dy[dir];
        snake_x+=dx[dir];
        //printf("%d, %d %d\n",snake_y,snake_x,dir);
        if (snake_y<0||snake_y>=N||snake_x<0||snake_x>=N||mp[snake_y][snake_x]==1){
            break;
        }
        if (mp[snake_y][snake_x]!=2){
            mp[tail.first][tail.second]=0;
            int tail_dir=dir_mp[tail.first][tail.second];
            tail.first+=dy[tail_dir];
            tail.second+=dx[tail_dir];
        }
        mp[snake_y][snake_x]=1;
        cnt++;
        if (q.size()&&cnt==q.front().first){
            if (q.front().second=='L'){
                dir=dir==0?3:dir-1;
            }
            else{
                dir=(dir+1)%4;
            }
            q.pop();
        }      
    }
    return cnt;
}

int main()
{
    cin >> N >> K;
    for (int i=0;i<K;i++){
        int apple_y,apple_x;
        cin >> apple_y >> apple_x;
        mp[apple_y-1][apple_x-1]=2;
    }
    cin >> L;
    for (int i=0;i<L;i++){
        int sec; char temp_dir;
        cin >> sec >> temp_dir;
        q.push({sec,temp_dir});
    }
    cout << snake()+1;
}