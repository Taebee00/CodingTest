#include <bits/stdc++.h>

using namespace std;

typedef struct _shark{
    bool exist;
    int speed;
    int dir;
    int sz;
}shark;

int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};

int R,C,M,sum=0;
shark mp[101][101];
vector <pair<int,int>> v;

int main(){
    
    cin >> R >> C >> M;

    for (int i=0;i<M;i++){
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        mp[r][c]={1,s,d-1,z};
        v.push_back({r,c});
    }

    for (int i=1;i<=C;i++){
        printf("%d번:\n",i);
        for (int j=1;j<=R;j++){
            if (mp[j][i].exist){
                sum+=mp[j][i].sz;
                mp[j][i].exist=0;
            }
        }
        vector<pair<int,int>> temp_v;  
        while(!v.empty()){
            int y=v.back().first;
            int x=v.back().second;
            int dir=mp[y][x].dir;
            int speed=mp[y][x].speed;
            int sz=mp[y][x].sz;
            int temp_y=y;
            int temp_x=x;      

            if (mp[y][x].exist){
                printf("%d %d\n",y,x); 
                if (dir==0||dir==1){                   
                    while(speed--){
                        if (temp_y+dy[dir]<1||temp_y+dy[dir]>R){
                            dir=dir==1?0:1;
                        }
                        temp_y+=dy[dir];
                    }
                }
                else{
                    while(speed--){
                        if (temp_x+dx[dir]<1||temp_x+dx[dir]>C){
                            dir=dir==2?3:2;
                        }
                        temp_x+=dx[dir];
                    }
                }
                if (mp[temp_y][temp_x].exist){
                    if (temp_y==y&&temp_x==x){
                        mp[temp_y][temp_x]=mp[y][x];
                        temp_v.push_back({temp_y,temp_x});
                    }
                    else if (mp[temp_y][temp_x].sz<sz){
                        mp[temp_y][temp_x]=mp[y][x];
                        mp[y][x].exist=0;
                    }
                    else{
                        temp_v.push_back({temp_y,temp_x});
                    }                   
                }
                else{
                    mp[temp_y][temp_x]=mp[y][x];
                    mp[y][x].exist=0;
                    temp_v.push_back({temp_y,temp_x});
                }
                
            }         
            v.pop_back();
        }
        v=temp_v;
    }
    cout << sum;
}