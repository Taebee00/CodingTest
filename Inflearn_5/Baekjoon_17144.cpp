#include <bits/stdc++.h>

using namespace std;

int R,C,T, sum=0, mp[50][50], temp_mp[50][50];
int clean_top, clean_bot;

void spread(int _y,int _x)
{
    int dy[4]={-1,0,1,0};
    int dx[4]={0,1,0,-1};
    int spread_cnt=0;

    for (int i=0;i<4;i++){
        int y=_y+dy[i];
        int x=_x+dx[i];
        if (y>=0&&y<R&&x>=0&&x<C&&temp_mp[y][x]!=-1){
            spread_cnt++;
            mp[y][x]+=temp_mp[_y][_x]/5;
        }
    }

    mp[_y][_x]-=temp_mp[_y][_x]/5*spread_cnt;
}

int main()
{
    cin >> R >> C >> T;
    int flag=0;
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> mp[i][j];
            
            if (mp[i][j]==-1&&!flag){
                clean_top=i;
                clean_bot=i+1;
                flag=1;
            }
        }
    }
    while(T--){
        sum=0;
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                temp_mp[i][j]=mp[i][j];
            }
        }
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                if (temp_mp[i][j]&&temp_mp[i][j]!=-1){
                    spread(i,j);
                }
            }
        }
        for (int i=clean_top;i>0;i--){
            mp[i][0]=mp[i-1][0];
        }
        for (int i=0;i<C-1;i++){
            mp[0][i]=mp[0][i+1];
        }
        for (int i=0;i<clean_top;i++){
            mp[i][C-1]=mp[i+1][C-1];
        }
        for (int i=C-1;i>1;i--){
            mp[clean_top][i]=mp[clean_top][i-1];
        }     
        mp[clean_top][0]=-1;
        mp[clean_top][1]=0;

        for (int i=clean_bot;i<R-1;i++){
            mp[i][0]=mp[i+1][0];
        }
        for (int i=0;i<C-1;i++){
            mp[R-1][i]=mp[R-1][i+1];
        }
        for (int i=R-1;i>clean_bot;i--){
            mp[i][C-1]=mp[i-1][C-1];
        }
        for (int i=C-1;i>0;i--){
            mp[clean_bot][i]=mp[clean_bot][i-1];
        }   
        mp[clean_bot][0]=-1;
        mp[clean_bot][1]=0;

        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                if (mp[i][j]!=-1){
                    sum+=mp[i][j];
                }
            }
        }
    }
    cout << sum;
}