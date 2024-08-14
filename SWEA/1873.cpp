#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
map<char,int> mp;

int main()
{
    mp['U']=0;
    mp['R']=1;
    mp['D']=2;
    mp['L']=3;
    int TC;
    cin >> TC;
    for (int i=1;i<=TC;i++){
        int H, W, dir, y, x;
        char arr[20][20];
        cin >> H >> W;
        for (int j=0;j<H;j++){
            for (int k=0;k<W;k++){
                cin >> arr[j][k];
                if (arr[j][k]=='^') dir=0, y=j, x=k;
                else if (arr[j][k]=='>') dir=1, y=j, x=k;
                else if (arr[j][k]=='v') dir=2, y=j, x=k;
                else if (arr[j][k]=='<') dir=3, y=j, x=k;
            }
        }
        int N;
        cin >> N;
        for (int j=0;j<N;j++){
            //cout << y << " " << x << "\n";
            char cmd;
            cin >> cmd;
            if (cmd=='S'){
                int bullet_y=y, bullet_x=x;
                while(1){
                    if (bullet_y<0||bullet_x<0||bullet_y>=H||bullet_x>=W||arr[bullet_y][bullet_x]=='#') break;
                    if (arr[bullet_y][bullet_x]=='*'){
                        arr[bullet_y][bullet_x]='.';
                        break;
                    }
                    bullet_y+=dy[dir], bullet_x+=dx[dir];
                }
            }
            else{
                dir=mp[cmd];
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                if (ny>=0&&nx>=0&&ny<H&&nx<W&&arr[ny][nx]=='.'){
                    arr[y][x]='.';
                    y=ny, x=nx;
                }
            }
        }
        char dir_arr[4]={'^','>','v','<'};
        printf("#%d ",i);
        for (int j=0;j<H;j++){
            for (int k=0;k<W;k++){
                if (j==y&&k==x){
                    printf("%c",dir_arr[dir]);
                    continue;
                }
                printf("%c",arr[j][k]);
            }
            printf("\n");
        }
    }
}